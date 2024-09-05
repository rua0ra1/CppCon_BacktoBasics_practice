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






int main (){

    example3();

}