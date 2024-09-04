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

int main (){

}