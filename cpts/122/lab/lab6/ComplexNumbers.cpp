#include "ComplexNumbers.hpp"
#include <stdio.h>

namespace ComplexNumbers {
    // Member add
    Complex &Complex::add(Complex const &other) {
        m_real += other.m_real;
        m_imaginary += other.m_imaginary;
        return *this;
    }

    Complex add(Complex const &c1, Complex const &c2){
        auto c = Complex();
        c.add(c1);
        c.add(c2);
        return c;
        
    }

    Complex operator+(Complex const &c1, Complex const &c2) {
        return add(c1, c2);
    }

    // c1 - c2 = c1 + -c2
    Complex operator-(Complex const &c1, Complex const &c2) {
        auto subtractor = Complex(
            -1 * c2.getReal(), 
            -1 * c2.getImaginary()
        );
        return add(c1, subtractor);
    }

    Complex read() {
        double real = 0;
        double imaginary = 0;
        scanf("%lf + %lfi", &real, &imaginary);
        return *new Complex(real, imaginary);
    }
}

