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