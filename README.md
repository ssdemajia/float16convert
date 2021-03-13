# float16convert
interchange 16bit float

半精度浮点数主要应用在GPU中，相对于float32能减少一半的内存消耗。float16可以取到的值范围是2.98e-8到65504
``` 
**   IEEE 758-2008 Half-precision Floating Point Format
**   --------------------------------------------------
**
**   | Field    | Last | First | Note
**   |----------|------|-------|----------
**   | Sign     | 15   | 15    |
**   | Exponent | 14   | 10    | Bias = 15
**   | Fraction | 9    | 0     |
```
# 参考
1. 格式介绍 http://fpmurphy.blogspot.com/2008/12/half-precision-floating-point-format_14.html
2. c++ 二进制输出 https://blog.csdn.net/jun2016425/article/details/52073281
3. 特殊值介绍 https://blog.csdn.net/Miracle_cx/article/details/89463503
4. IEEE 754 https://www.wikiwand.com/zh/IEEE_754
5. wiki half float https://zh.wikipedia.org/wiki/%E5%8D%8A%E7%B2%BE%E5%BA%A6%E6%B5%AE%E7%82%B9%E6%95%B0
6. 32位float https://www.jianshu.com/p/0a5f69161c28