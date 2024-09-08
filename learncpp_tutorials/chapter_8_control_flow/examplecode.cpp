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

//example 3 sequential case labels
/* 
bool isVowel(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
        c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}
 switch (c)
    {
    case 'a': // if c is 'a'
    case 'e': // or if c is 'e'
    case 'i': // or if c is 'i'
    case 'o': // or if c is 'o'
    case 'u': // or if c is 'u'
    case 'A': // or if c is 'A'
    case 'E': // or if c is 'E'
    case 'I': // or if c is 'I'
    case 'O': // or if c is 'O'
    case 'U': // or if c is 'U'
        return true;
    default:
        return false;
    }

 */

int main(){
    
}