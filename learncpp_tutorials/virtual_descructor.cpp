#include <iostream>

class Base {
public:
     ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor called" << std::endl;
    }
};

int main() {
    Base* obj = new Derived();
    delete obj; // Properly calls Derived destructor first, then Base destructor
    return 0;
}
