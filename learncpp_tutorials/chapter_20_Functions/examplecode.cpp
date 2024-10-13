/* // function pointer
#include<iostream>

int foo()
{
    return 5;
}

int main(){
    // function prototypes
int foo();

// function initializations
int (*fcnPtr5)() { foo }; // okay, foo implicitly converts to function pointer to foo
void* vPtr { foo };       // not okay, though some compilers may allow
} */

// calling a function using a function pointer explicit dereferencing
#include<iostream>

int foo(int x){
    return x;
}

int main(){
    int (*fcnptr)(int){&foo};
    
}