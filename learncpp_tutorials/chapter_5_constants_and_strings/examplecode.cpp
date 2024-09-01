#include<iostream>

void example1(){
    std::cout<< "enter your age: ";
    int age{};
    std::cin>>age;

    const int constAge{age};
    age =5;
    //constAge =6;  we can initialize const with non const varible value
}

// calling the the function with const value

void example2(const int a ){
    std::cout<<"the value of a in ex2 is"<<a<< "\n";

}
void example3(){
    const int age=40; // compile time constant 
    const double pi=3.1415;// run time constant because it non integral with const initalization
    constexpr double pi_expr=3.1415; // compile time constant
}

// example 4
int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;

    return y;
}

void example4(){
    // Non-const variables are always non-constants:
    int a { 5 };                 // 5 is a constant expression
    double b { 1.2 + 3.4 };      // 1.2 + 3.4 is a constant expression

    // Const integral variables with a constant expression initializer are compile-time constants:
    const int c { 5 };           // 5 is a constant expression
    const int d { c };           // c is a constant expression
    const long e { c + 2 };      // c + 2 is a constant expression

    // Other const variables are runtime constants:
    const int f { a };           // a is not a constant expression
    const int g { a + 1 };       // a + 1 is not a constant expression
    const int h { a + c };       // a + c is not a constant expression
    const int i { getNumber() }; // getNumber() is not a constant expression

    const double j { b };        // b is not a constant expression
    const double k { 1.2 };      // 1.2 is a constant expression
}

// example 5

int  five(){
    return 5;
}

void example5()
{

    constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something { sum };  // ok: sum is a constant expression

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    //constexpr int myAge { age };      // compile error: age is not a constant expression
    // constexpr int f { five() };       // compile error: return value of five() is not a constant expression

}

// example6
constexpr int add(int x,int y){
    return x+y;
}

constexpr float multiply(float x,float y){
    return x+y;
}

void  example6(){
    constexpr int result1= add(5,6);
   constexpr float a=3; constexpr float b=7;

    constexpr float result2=multiply(a,b);
}

void example7(){
    constexpr bool inBigClassroom { false };
    constexpr int classSize { inBigClassroom ? 30 : 20 };
    std::cout << "The class size is: " << classSize << '\n';
}


int main(){
    // example1();
    //example2(a);
    //  example3();
    example6();
}