#include<iostream>
#include <typeinfo>
#include<type_traits>
#include<optional>
#include <string>
#include <fstream>



/* example 1 */
int return5()
{
    return 5;
}
void example1(){
      int x{ 5 }; // 5 is an rvalue expression
    const double d{ 1.2 }; // 1.2 is an rvalue expression

    int y { x }; // x is a modifiable lvalue expression
    const double e { d }; // d is a non-modifiable lvalue expression
    int z { return5() }; // return5() is an rvalue expression (since the result is returned by value)

    int w { x + 1 }; // x + 1 is an rvalue expression
    int q { static_cast<int>(d) }; // the result of static casting d to an int is an rvalue expression
/* You may be wondering why return5(), x + 1, and static_cast<int>(d) are rvalues: the answer is because these expressions produce temporary values that are not identifiable objects. */

}


/* example 2 */
void exmaple2(){
    int x { 5 };
    int y { 6 };

    int& ref { x }; // ref is now an alias for x

    ref = y; // assigns 6 (the value of y) to x (the object being referenced by ref)
    // The above line does NOT change ref into a reference to variable y!

    std::cout << x << '\n'; // user is expecting this to print 5
}

/* example3 */
void example3(){
    int x{5};
    const int& ref{x};
    std::cout<<ref <<'\n';
    x=6;

    std::cout<< " value "<<x<<" ref"<< ref<<'\n';
}

/* example 4 */
// int g_x{5};

// int example4(){
//         [[maybe_unused]] constexpr int& ref1 { g_x }; // ok, can bind to global

//     static int s_x { 6 };
//     [[maybe_unused]] constexpr int& ref2 { s_x }; // ok, can bind to static local

//     int x { 6 };
//    // [[maybe_unused]] constexpr int& ref3 { x }; // compile error: can't bind to non-static object
//    static const int s_x { 6 }; // a const int
//    [[maybe_unused]] constexpr const int& ref2 { s_x }; // needs both constexpr and const

// }

/* example 5 */

void foo(int a, int& b, const std::string& c){

    std::cout<<" foo is called "<<'\n';

}

void example5(){
    int x { 5 };
    const std::string s { "Hello, world!" };

    foo(5, x, s);
}

// /* pointer to cont */
// void example6(){
//     const int x{5};
//     const int * ptr {&x};
//     // *ptr=10; we can change the value of the address it pointing to
//     const int y{6};
//     ptr=&y;
// }

// /*  const pointers */
// void example7(){
//     const int x{5};
//     int* const ptr {&x}; // const after the asterisk means that is a const pointer
//     int y{5};
// }

// const pointer to const value
void example6(){
    int value { 5 };
    const int* const ptr { &value }; // a const pointer to a const value
}


/* dont return non const static local variables by reference */
// const int& getNextId()
// {
//     static int s_x{ 0 }; // note: variable is non-const
//     ++s_x; // generate the next id
//     return s_x; // and return a reference to it
// }

// int example7()
// {
//     const int& id1 { getNextId() }; // id1 is a reference
//     const int& id2 { getNextId() }; // id2 is a reference

//     std::cout << id1 <<"  "<<id2 << '\n';

//     return 0;
// }

// std::string& getName()
// {
//     static std::string s_name{};
//     std::cout << "Enter a name: ";
//     std::cin >> s_name;
//     return s_name;
// }

// void printFirstAlphabetical(std::string_view s1, std::string_view s2)
// {
//     if (s1 < s2)
//         std::cout << s1 << " comes before " << s2 << '\n';
//     else
//         std::cout << s2 << " comes before " << s1 << '\n';
// }
/* exmaple 8 */
// A top level const is a const qualifier that applies to an object itself.#include <typeinfo>

/* 
const int x;    // this const applies to x, so it is top-level
int* const ptr; // this const applies to ptr, so it is top-level
*/
/* 
const int& ref; // this const applies to the object being referenced, so it is low-level
const int* ptr; // this const applies to the object being pointed to, so it is low-level
 */
/* 
const int* const ptr; // the left const is low-level, the right const is top-level
*/

// In contrast, a lowel level const is const qualifer that  applies to the oject beign referenced or pointed to
std::string ReadStringFromFile(const std::string& filepath){
    std::ifstream streamm(filepath);
    if (streamm){
         std::string result;
        //read file 
        streamm.close();
       
        return result;
    }
    return std::string();

}

int main(){
    return 0;
   
}