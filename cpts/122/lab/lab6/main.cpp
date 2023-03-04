#include "ComplexNumbers.hpp"
using namespace ComplexNumbers;
int main(int argc, char const *argv[])
{
    auto c1 = Complex(1, 0);
    auto c2 = Complex(0, 1);
    auto c3 = c1 + c2;
    auto c4 = c1 - c2;

    return 0;
}
