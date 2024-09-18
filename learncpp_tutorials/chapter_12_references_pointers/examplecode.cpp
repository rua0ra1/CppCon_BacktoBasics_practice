#include<iostream>

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

int main(){
    example3();

}