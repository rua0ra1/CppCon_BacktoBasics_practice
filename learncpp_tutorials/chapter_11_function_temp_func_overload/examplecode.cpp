/* #include<iostream>

template <typename T> // template parameter declaration
T max(T x, T y)
{
    return (x<y)?y:x;
}

int max(int x, int y){
    std::cout<<" normal funciton is callled "<<"\n";
    return 0;
}

int main(){

    double y =  max<>(5,6);

    std::cout<< " the max value is :"<< y <<'\n';

} */

/* #include <iostream>
#include <string>

template <typename T>
T addOne(T x)
{
    return x + 1;
}

// Use function template specialization to tell the compiler that addOne(const char*) should emit a compilation error
// const char* will match a string literal
template <>
std::string addOne(std::string x) = delete;

int main()
{
    std::cout << addOne("Hello, world!") << '\n'; // compile error

    return 0;
} */
/* 
#include<iostream>

template <typename T, typename U>

auto max(T x, U y){
    return (x<y)?y:x;
}

int main(){
    std::cout<<max(2,3.5)<<"\n";
    return 0;
} */

// Defining our own non type template parameters
 
#include<iostream>

template <int N>
void print(){
    std::cout<< N << '\n';
}

int main(){
    print<5> ();
}