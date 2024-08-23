#include <iostream>

class Base {
public:
    int baseData;

    Base(int val) : baseData(val) {}

    virtual void show() const {
        std::cout << "Base class, baseData: " << baseData << std::endl;
    }
};

class Derived : public Base {
public:
    int derivedData;

    Derived(int baseVal, int derivedVal) : Base(baseVal), derivedData(derivedVal) {}

    void show() const override {
        std::cout << "Derived class, baseData: " << baseData << ", derivedData: " << derivedData << std::endl;
    }
};

void display(Base &b) {
    b.show();  // Will only call Base::show(), even if a Derived object is passed
}

int main() {
    Derived d(10, 20);
    
    display(d);  // Object slicing occurs here

    return 0;
}
