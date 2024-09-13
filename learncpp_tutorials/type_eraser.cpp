#include <iostream>
#include <memory>

// Base interface that hides the actual type
class Printable {
public:
    virtual ~Printable() = default;  // Virtual destructor for cleanup
    virtual void print() const = 0;  // Pure virtual function to be overridden
};

// Template that implements the interface for any type T
template <typename T>
class PrintableImpl : public Printable {
    T obj;  // The actual object
public:
    PrintableImpl(T obj) : obj(std::move(obj)) {}  // Constructor
    void print() const override {  // Implement the print function
        obj.print();  // Call the object's print method
    }
};

// Type-erased wrapper that can store any printable object
class AnyPrintable {
    std::unique_ptr<Printable> ptr;  // Pointer to base Printable class
public:
    // Constructor that accepts any type with a print method
    template <typename T>
    AnyPrintable(T obj) : ptr(std::make_unique<PrintableImpl<T>>(std::move(obj))) {}

    // Call print on the stored object
    void print() const {
        ptr->print();
    }
};

// Example class 1 with a print method
class Foo {
public:
    void print() const {
        std::cout << "Foo::print" << std::endl;
    }
};

// Example class 2 with a print method
class Bar {
public:
    void print() const {
        std::cout << "Bar::print" << std::endl;
    }
};

int main() {
    Foo foo;  // Create an object of type Foo
    Bar bar;  // Create an object of type Bar

    AnyPrintable anyFoo(foo);  // Store Foo in the type-erased wrapper
    AnyPrintable anyBar(bar);  // Store Bar in the type-erased wrapper

    anyFoo.print();  // Output: Foo::print
    anyBar.print();  // Output: Bar::print

    return 0;
}
