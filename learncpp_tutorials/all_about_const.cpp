// #include <bitset> // for std::bitset
// #include <iostream>

// int main()
// {
// 	// std::bitset<8> means we want to store 8 bits
// 	std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
// 	std::bitset<8> bin2{ 0xC5 }; // hexadecimal literal for binary 1100 0101

// 	std::cout << bin1 << '\n' << bin2 << '\n';
// 	std::cout << std::bitset<4>{ 1 } << '\n'; // create a temporary std::bitset and print it

// 	return 0;
// }

#include <format> // C++20
#include <iostream>
#include <print> // C++23

int main()
{
    std::cout << std::format("{:b}\n", 0b1010);  // C++20, {:b} formats the argument as binary digits
    std::cout << std::format("{:#b}\n", 0b1010); // C++20, {:#b} formats the argument as 0b-prefixed binary digits

    std::println("{:b} {:#b}", 0b1010, 0b1010);  // C++23, format/print two arguments (same as above) and a newline

    return 0;
}