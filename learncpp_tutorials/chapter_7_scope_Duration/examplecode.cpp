#include <iostream>

//example 1
int add(int x, int y)
{ // start block
    return x + y;
} // end block (no semicolon)

void example1(){
     // multiple statements
    int value {}; // this is initialization, not a block
    add(3, 4);
}

void example2(){
    
    int x { 2 }; // local variable, no linkage

    {
        int x { 3 }; // this declaration of x refers to a different object than the previous x
    }

}

// example 3 of the name shadowing 
void example3(){
    int apple {5};

    {
        std::cout<< apple <<'\n';
        int apple {0};
        // apples now refers to the nested block apples
        // the outer block apples is temporarily hidden

        apple = 10; // this assigns value 10 to nested block apples, not outer block apples

        std::cout << apple << '\n'; // print value of nested block apples
    }

        std::cout << apple << '\n'; // prints value of outer block apples

}
/*
//example 4 internal linkage of non const and const global variable
// to make non const global variable internal, we use the static keyword
static int g_x{}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword
const int g_y{ 1 }; // const globals have internal linkage by default
constexpr int g_z{ 2 }; // constexpr globals have internal linkage by default
 */

/* 
//example 5
int g_x { 2 }; // non-constant globals are external linkage by default
extern const int g_y { 3 }; // const globals can be defined as extern, making them external
extern constexpr int g_z { 3 }; // constexpr globals can be defined as extern, 
making them external (but this is pretty useless, see the warning in the next section)

// non-constant
int g_x; // variable definition (can have initializer if desired)
extern int g_x; // forward declaration (no initializer)

// constant
extern const int g_y { 1 }; // variable definition (const requires initializers)
extern const int g_y; // forward declaration (no initializer)
*/

/* 
//example 6
// Forward declarations:
extern int g_y;                // forward declaration for non-constant global variable
extern const int g_y;          // forward declaration for const global variable
extern constexpr int g_y;      // not allowed: constexpr variables can't be forward declared

// External global variable definitions:
int g_x;                       // defines non-initialized external global variable (zero initialized by default)
extern const int g_x{ 1 };     // defines initialized const external global variable
extern constexpr int g_x{ 2 }; // defines initialized constexpr external global variable
*/

/* example 7

namespace constants
{
    constexpr double gravity { 9.8 }; // has internal linkage, is accessible only within this file
}

double getGravity() // has external linkage, can be accessed by other files
{
    // We could add logic here if needed later
    // or change the implementation transparently to the callers
    return constants::gravity;
}
Global const variables have internal linkage by default, gravity doesn’t need to be static.
*/

/* example 8

#ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace constants
{
    // constants have internal linkage by default
    constexpr double pi { 3.14159 };
    constexpr double avogadro { 6.0221413e23 };
    constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif

*/



/* example 9

#ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace constants
{
    inline constexpr double pi { 3.14159 }; // note: now inline constexpr
    inline constexpr double avogadro { 6.0221413e23 };
    inline constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif

#include "constants.h"

#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}

*/

/* // example 10

#include <iostream>

void increamentAndPrint(){
   static int value{1};// automatic duration by default
    ++value;
    std::cout<<value<<'\n';

} */


//example 11
int generateID()
{
    static int s_itemID;
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

// example 12

/* int main()
{
   using std::cout; // this using declaration tells the compiler that cout should resolve to std::cout
   cout << "Hello world!\n"; // so no std:: prefix is needed here!

   return 0;
} // the using declaration expires at the end of the current scope


#include <iostream>

int main()
{
   using namespace std; // all names from std namespace now accessible without qualification
   cout << "Hello world!\n"; // so no std:: prefix is needed here

   return 0;
} // the using-directive ends at the end of the current scope
 */


//example 13

/* 
int main()
{
    {
        using namespace Foo;
        // calls to Foo:: stuff here
    } // using namespace Foo expires

    {
        using namespace Goo;
        // calls to Goo:: stuff here
    } // using namespace Goo expires

    return 0;
}
 */

//example 14 

inline namespace V1
{
    void doSomething(){
          std::cout << "V1\n";
    }
}

namespace V2 // declare a normal namespace named V2
{
    void doSomething()
    {
        std::cout << "V2\n";
    }
}

int main()
{
    V1::doSomething(); // calls the V1 version of doSomething()
    V2::doSomething(); // calls the V2 version of doSomething()

    doSomething(); // calls the inline version of doSomething() (which is V1)

    return 0;
}

