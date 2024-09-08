#include<iostream>

// example 1

void example1(){
    constexpr double gravity {9.8};
    if constexpr (gravity == 9.8) // now using constexpr if
		std::cout << "Gravity is normal.\n";
	else
		std::cout << "We are not on Earth.\n";

}

//example 2

void printDigitName(int x){
     if (x == 1)
        std::cout << "One";
    else if (x == 2)
        std::cout << "Two";
    else if (x == 3)
        std::cout << "Three";
    else
        std::cout << "Unknown";
}

void example2(){
   printDigitName(2);
}

int main(){
    
}