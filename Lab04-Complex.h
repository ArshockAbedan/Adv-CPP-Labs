class Complex
{
private:
    double real;
    double imaginary;

public:
    // default constructor
    Complex()
    {
        real = 0.0;
        imaginary = 0.0;
    }

    // Parameterized constructor
    Complex(double real, double imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    // Getters
    double getReal()
    {
        return real;
    }

    double getImaginary()
    {
        return imaginary;
    }

    // A member function for overloading '+' operator for this class.
    Complex operator+(Complex &operand)
    {
        Complex temp;
        temp.real = this->real + operand.real;
        temp.imaginary = this->imaginary + operand.imaginary;
        return temp;
    }

    // A member function for overloading '-' operator for this class.
    Complex operator-(Complex &operand)
    {
        Complex temp;
        temp.real = this->real - operand.real;
        temp.imaginary = this->imaginary - operand.imaginary;
        return temp;
    }

    // A member function for overloading '*' operator for this class.
    Complex operator*(Complex &operand)
    {
        return Complex((real * operand.real) - (imaginary * operand.imaginary),
                       (real * operand.imaginary) + (imaginary * operand.real));
    }

    // A member function for overloading Comparison operator for this class.
    bool operator==(Complex &operand)
    {
        return (operand.real == this->real) && (operand.imaginary == this->imaginary);
    }
};
