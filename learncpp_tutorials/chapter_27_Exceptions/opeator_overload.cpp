#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload the '+' operator to add two Complex objects
    Complex operator () (const Complex& other) {
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }

    // Function to display complex number
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);

    Complex c3 = c1 (c2);  // Calls overloaded + operator

    std::cout << "c1: "; c1.display();
    std::cout << "c2: "; c2.display();
    std::cout << "Sum: "; c3.display();

    return 0;
}
