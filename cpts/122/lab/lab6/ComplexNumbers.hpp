namespace ComplexNumbers {
    class Complex {

    double m_real;
    double m_imaginary;

    public:
        Complex(double real = 0, double imaginary = 0) 
            : m_real(real), m_imaginary(imaginary)
        {};

        Complex &add(Complex const &other);

        double getReal() const {return m_real;}
        double getImaginary() const {return m_imaginary;}
    };

    Complex add(Complex const &c1, Complex const &c2);

    Complex operator+(Complex const &c1, Complex const &c2);

    Complex operator-(Complex const &c1, Complex const &c2);

    Complex read();
}