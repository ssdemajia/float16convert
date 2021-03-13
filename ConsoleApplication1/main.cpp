#include <iostream>
#include <bitset>
#include "float16.h"
using namespace std;
int main()
{
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    Float16::Converter c;
    c.i = 0x7f800000;
    std::cout << c.f << std::endl;
    c.i = 0xff800000;
    std::cout << c.f << std::endl;

    c.i = 0x7f800001;
    std::cout << c.f << std::endl;
    c.i = 0xff800041;
    std::cout << c.f << std::endl;

    c.i = 0x80000000;
    std::cout << c.f << std::endl;
    c.i = 0x00000000;
    std::cout << c.f << std::endl;

   
    c.f = 0.125f;
    cout << bitset<sizeof(float) * 8>(c.i) << endl;
    auto v = Float16::floatToHalf(c.f);
    cout << bitset<sizeof(uint16_t) * 8>(v) << endl;
    std::cout << Float16::halfToFloat(v) << std::endl;
}