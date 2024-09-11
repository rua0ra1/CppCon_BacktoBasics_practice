#include<iostream>

/* ------------ example 1 --------------------
*/

#include <iostream>

void blowUpWorld()
{
    std::cout << "Kaboom!\n";
}

void example1(){
    std::cout << "Should we blow up the world again? (y/n): ";
    char c{};
    std::cin >> c;

    if (c == 'y');     // accidental null statement here
        blowUpWorld(); // so this will always execute since it's not part of the if-statement
}

int main()
{
    example1();
        
}

