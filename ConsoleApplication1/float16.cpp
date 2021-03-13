#include "float16.h"

namespace Float16 {
	float halfToFloat(HALF value) {
		Converter v;
		v.i = halfToInt32(value);
		return v.f;
	}

	HALF floatToHalf(float value) {
		Converter v;
		v.f = value;
		return int32ToHalf(v.i);
	}

	uint32_t halfToInt32(HALF value) {
		int sign = (value >> 15) & 0x0001;
		int exp = (value >> 10) & 0x001f;
		int frac = value & 0x03ff;

		if (exp == 0) {
			if (frac == 0) {
				return sign << 31;  // +0和-0
			}
			else {
				while (!(frac & 0x00000400)) {
					frac <<= 1;
					exp -= 1;
				}
				exp += 1;
				frac &= ~0x00000400;
			}
		}
		else if (exp == 31){ // 0x11111
			if (frac == 0) {
				return (sign << 31) | 0x7f80000;  // inf
			}
			else {
				return (sign << 31) | 0x7f800000 | (frac << 13);  // nan
			}
		}

		exp = exp + 127 - 15;
		frac = frac << 13;

		return ((sign << 31) | (exp << 23) | frac);
	}

	HALF int32ToHalf(uint32_t value) {
		// 这里的value其实是一个32位float
		int sign = value & 0x80000000;
		int exp = (value >> 23);
		exp = exp & 0x000000ff;
		exp = exp - 127;  // 获得32位浮点数的指数位（8位）
		// 现在需要将其映射到16位浮点数的指数位（5位，-15+x=exp, x为新的指数位）
		exp = 15 + exp; // 15位指数偏移值
		int frac = value & 0x7fffff;

		if (exp <= 0) {
			if (exp < -10) {
				if (sign) {
					return 0x8000;  // -0.0
				}
				else {
					return 0; // 0
				}
			}
			frac = (frac | 0x00800000) >> (1 - exp);
			return sign | (frac >> 13);
		}
		else if (exp == 0xff - 112) {
			if (frac == 0) {
				return sign | 0x7c00;
			}
			else {
				frac >>= 13;
				return sign | 0x7c00 | frac | (frac == 0);
			}
		}
		else {
			if (exp > 30) {
				return sign | 0x7c00;
			}
			return sign | (exp << 10) | (frac >> 13);
		}
		return 1;
	}
}