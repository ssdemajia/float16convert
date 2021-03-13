#ifdef FLOAT_16_CONVERT_H
#define FLOAT_16_CONVERT_H
#endif // FLOAT_16_CONVERT_H

#include <iostream>
#include <cstdint>
namespace Float16 {
	typedef uint16_t HALF;
	union Converter {
		float f;
		uint32_t i;
	};
	float halfToFloat(HALF);
	HALF floatToHalf(float);

	uint32_t halfToInt32(HALF);
	HALF int32ToHalf(uint32_t);
}