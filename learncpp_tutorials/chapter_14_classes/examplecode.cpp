#include <iostream>
#include <string>
/* example 1 */
// enum AnimalType
// {
//     cat,
//     dog,
//     chicken,
// };

// constexpr std::string_view animalName(AnimalType type){
//     switch(type){
//         case cat: return "cat";
//         case dog: return "dog";
//         case chicken: return "chicken";
//         default: return " ";
//     }
// }

// constexpr int numLegs(AnimalType type){
//     switch (type)
//     {
//     case cat: return 4;#include <string_view>

//   int day{};
//   int month{};
//   int year{};
//   void printDate() {
//     std::cout << day << "/" << month << '/' << year;
//   }
// };


// /* example 3 const member function */
// struct Date{
//      const int year{10};
//      const int month{22};
//      const int day{23};

//     void print() const  {
//         std::cout<<year<<'/'<< month<<'/'<<day;
//     }

// };

// void doSomething(const Date& date){
//     date.print();
// }

// /* exampkle 4 access levels work on a per class basis */
// class Person
// {
// private:
//     std::string m_name{};

// public:
//     void kisses(const Person& p) const
//     {
//         std::cout << m_name << " kisses " << p.m_name << '\n';
//     }

//     void setName(std::string name)
//     {
//         m_name = name;
//     }
// };

/* returning data members by lvalue reference */#include <iostream>
// #include <string>

// class Employee
// {
// 	std::string m_name{};

// public:
// 	void setName(std::string name) { m_name = name; }
// 	const std::string& getName() const { return m_name; } //  getter returns by const reference
// };

// int main()
// {
// 	Employee joe{}; // joe exists until end of function
// 	joe.setName("Joe");

//   auto get_name=joe.getName();
//   get_name="changed";

// 	std::cout << get_name; // returns joe.m_name by reference

// 	return 0;
// }
/* return rvalue reference form the class */
// #include <iostream>
// #include <string>
// #include <string_view>

// class Employee
// {
// 	std::string m_name{};

// public:
// 	void setName(std::string_view name) { 
//     m_name = name; 
//     }
// 	const std::string& getName() const { return m_name; } //  getter returns by const reference
// };

// // createEmployee() returns an Employee by value (which means the returned value is an rvalue)
// Employee createEmployee(std::string_view name)
// {
// 	Employee e;
// 	e.setName(name);
// 	return e;
// }

// int main()
// {
// 	// Case 1: okay: use returned reference to member of rvalue class object in same expression
// 	std::cout << createEmployee("Frank").getName();

// 	// Case 2: bad: save returned reference to member of rvalue class object for use later
// 	const std::string& ref { createEmployee("Garbo").getName() }; // reference becomes dangling when return value of createEmployee() is destroyed
// 	std::cout << ref; // undefined behavior

// 	// Case 3: okay: copy referenced value to local variable for use later
// 	std::string val { createEmployee("Hans").getName() }; // makes copy of referenced member
// 	std::cout << val; // okay: val is independent of referenced member

// 	return 0;
// }

/*  // do not retunn non const reference to private variables */
/* #include <iostream>

class Foo
{
private:
    int m_value{ 4 }; // private member

public:
    int& value() const { return m_value; } // returns a non-const reference (don't do this)
};

int main()
{
    Foo f{};                // f.m_value is initialized to default value 4
    f.value() = 5;          // The equivalent of m_value = 5
    std::cout << f.value(); // prints 5

    return 0;
} */

// data hiding allowing us to maintain invariants
/* #include <iostream>
#include <string>

struct Employee // members are public by default
{
    std::string name{ "John" };
    char firstInitial{ 'J' }; // should match first initial of name

    void print() const
    {
        std::cout << "Employee " << name << " has first initial " << firstInitial << '\n';
    }
};

int main()
{
    Employee e{}; // defaults to "John" and 'J'
    e.print();

    e.name = "Mark"; // change employee's name to "Mark"
    e.print(); // prints wrong initial

    return 0;
}
 */

//  member intialization order
// #include <algorithm> // for std::max
// #include <iostream>

// class Foo
// {
// private:
//     int m_x{};
//     int m_y{};

// public:
//     Foo(int x, int y)
//         : m_y{ std::max(x, y) }, m_x{ m_y } // issue on this line
//     {
//     }

//     void print() const
//     {
//         std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
//     }
// };

// int main()
// {
//     Foo foo{ 6, 7 };
//     foo.print();

//     return 0;
// }

// member initializer list vs default member initializers

/* #include <iostream>

class Foo
{
private:
    int m_x{5};    // default member initializer (will be ignored)
    int m_y{ 10 }; // default member initializer (will be used)
    int m_z;      // no initializer

public:
    Foo(int x)
        : m_x{ x } // member initializer list
    {
        std::cout << "Foo constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }
};

int main()
{
    Foo foo{ 6 };
    foo.print();

    return 0;
} */

// constructor function bodies
// Foo(int x, int y)
//     {
//         m_x = x; // incorrect: this is an assignment, not an initialization
//         m_y = y; // incorrect: this is an assignment, not an initialization
//     }

/* class Animal{
     
    public:
    int id;
    Animal(){
        std::cout << "Default Constructor called\n";
    }

};

int main(){
    Animal a;
    std::cout<<"it deafult initialization "<<a.id<<"\n";

    Animal b{};
    std::cout<<"it value initialization "<<b.id<<"\n";
    

} */

/* constructor with default arguments */
// #include <iostream>

// class Foo
// {
// private:
//     int m_x { };
//     int m_y { };

// public:
//     // Foo(){
//     //     std::cout<<"default constructor is called"<<'\n';
//     // }
//     Foo(int x, int y=0) // has default arguments
//         : m_x { x }
//         , m_y { y }
//     {
//         std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
//     }
// };

// int main()
// {
//     Foo foo1{};     // calls Foo(int, int) constructor using default arguments
//     Foo foo2{6, 7}; // calls Foo(int, int) constructor

//     return 0;
// }

// explicit defaulted default constructor

// #include <iostream>

// class Default
// {
// private:
//     int m_a; // note: no default initialization value
//     int m_b {};
    

// public:
//    int*p;
//    Default()=default; // explicitly defaulted default constructor

//     int a() const { return m_a; }
//     int b() const { return m_b; }
// };

// int main(){
//     Default def{}; // zero initialized, then default initialized
//     std::cout << def.a() << ' ' << def.b() << *def.p<< '\n';

// }

// only create default constructor when it makes sense
// #include <iostream>

// class Fraction
// {
// private:
//     int m_numerator{1};
//     int m_denominator{2};

// public:
//     Fraction(){}
//     Fraction(int numerator, int denominator)
//         : m_numerator{ numerator }
//         , m_denominator{ denominator }
//     {
//     }

//     void print() const
//     {
//         std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
//     }
// };

// int main()
// {
//     Fraction f1 {3, 5};
//     f1.print();

//     Fraction f2 {}; // will get Fraction 0/1
//     f2.print();
//     Fraction f3;
//     f3.print();

//     return 0;
// }

// #include<iostream>
// #include<string>
// #include<string_view>

// class Employee
// {
// private:
//     std::string m_name{};
//     int m_id{ 0 }; // default member initializer

// public:

//     Employee(std::string_view name, int id = 0) // default argument for id
//         : m_name{ name }, m_id{ id }
//     {
//         std::cout << "Employee " << m_name << " created\n";
//     }
// };

// int main()
// {
//     Employee e1{ "James" };
//     Employee e2{ "Dave", 42 };
// }

// temporary class objects
/* #include <iostream>

class IntPair
{
private:
    int m_x{};
    int m_y{};

public:
    IntPair(int x, int y)
        : m_x { x }, m_y { y }
    {}

    int x() const { return m_x; }
    int y() const { return m_y; }
};

void print(IntPair p)
{
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}

int main()
{
    // Case 1: Pass variable
    IntPair p { 3, 4 };
    print(p); // prints (3, 4)

    return 0;
} */ 
/* #include <iostream>

class IntPair
{
private:
    int m_x{};
    int m_y{};

public:
    IntPair(int x, int y)
        : m_x { x }, m_y { y }
    {}

    int x() const { return m_x; }
    int y() const{ return m_y; }
};

void print(IntPair p)
{
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}

int main()
{
    // Case 1: Pass variable
    IntPair p { 3, 4 };
    print(p);

    // Case 2: Construct temporary IntPair and pass to function
    print(IntPair { 5, 6 } );

    // Case 3: Implicitly convert { 7, 8 } to a temporary Intpair and pass to function
    print( { 7, 8 } );

    return 0;
} */

/* #include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    // Copy constructor
    Fraction(const Fraction& fraction)
        : m_numerator{ fraction.m_numerator }
        , m_denominator{ fraction.m_denominator }
    {
        std::cout << "Copy constructor called\n";
    }

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

void printFraction(Fraction f) // f is pass by value
{
    f.print();
}

Fraction generateFraction(int n, int d)
{
    Fraction f{ n, d };
    return f;
}

int main()
{
    Fraction f2 { generateFraction(1, 2) }; // Fraction is returned using copy constructor

    printFraction(f2); // f2 is copied into the function parameter using copy constructor

    return 0;
} */


/* int main(){
int a;         // no initializer (default initialization)
int b = 5;     // initializer after equals sign (copy initialization)
int c( 6 );    // initializer in parentheses (direct initialization)

// List initialization methods (C++11)
int d { 7 };   // initializer in braces (direct list initialization)
int e = { 8 }; // initializer in braces after equals sign (copy list initialization)
int f {};      // initializer is empty braces (value initialization)

std::cout<< "a: "<< a <<"f "<< f <<std::endl;
}
 */

/* #include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name{};

public:
    Employee(std::string_view name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
};

void printEmployee(Employee e) // has an Employee parameter
{
    std::cout << e.getName();
}

int main()
{ 
    using namespace std::literals;
    printEmployee("Joe"sv); // we're supplying an string literal argument
 return 0;
}*/

// the explicit keyword
/* #include <iostream>
class Dollars
{
private:
    int m_dollars{};

public:
     explicit Dollars(int d) // now explicit
        : m_dollars{ d }
    {
    }

    int getDollars() const { return m_dollars; }
};

void print(Dollars d)
{
    std::cout << "$" << d.getDollars();
}

int main()
{
    print(5); // compilation error because Dollars(int) is explicit

    return 0;
} */

// constexpr aggregates and classes
/* #include <iostream>

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    std::cout << greater(5, 6);        // greater(5, 6) may be evaluated at compile-time or runtime

    constexpr int g { greater(5, 6) }; // greater(5, 6) must be evaluated at compile-time
    std::cout << g;                    // prints 6

    return 0;
} */

// #include <iostream>

// struct Pair
// {
//     int m_x {};
//     int m_y {};

//     constexpr int  greater() const
//     {
//         return (m_x > m_y  ? m_x : m_y);
//     }
// };

// int main()
// {
//     constexpr Pair p { 5, 6 };                 // inputs are constexpr values
//     std::cout << p.greater();        // p.greater() evaluates at runtime

//     constexpr int g { p.greater() }; // compile error: greater() not constexpr
//     std::cout << g;

//     return 0;
// }

// constexpr clas objects and constexpr constructors
/* 
#include <iostream>

class Pair // Pair is no longer an aggregate
{
private:
    int m_x {};
    int m_y {};

public:
    constexpr Pair(int x, int y): m_x { x }, m_y { y } {}

    constexpr int greater() const
    {
        return (m_x > m_y  ? m_x : m_y);
    }
};

int main()
{
    constexpr Pair p { 5, 6 };       // compile error: p is not a literal type
    std::cout << p.greater();

    constexpr int g { p.greater() };
    std::cout << g;

    return 0;
} */

#include <iostream>

class Pair
{
private:
    int m_x {};
    int m_y {};

public:
    constexpr Pair(int x, int y): m_x { x }, m_y { y } {}

    constexpr int greater() const // constexpr and const
    {
        return (m_x > m_y  ? m_x : m_y);
    }

    constexpr void reset() // constexpr but not const
    {
        m_x = m_y = 0;
    }

    constexpr const int& getX() const { return m_x; }
};

// This function is constexpr
constexpr Pair zero()
{
    Pair p { 1, 2 }; // p is non-const
    p.reset();       // call constexpr member function on non-const object
    return p;
}

int main()
{
    constexpr Pair p2 { zero() }; // zero() must evaluate at compile-time
    std::cout << p2.getX();       // prints 0

    return 0;
}
