#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <cstdint>
#include<cstddef> // for std::size_t 

void example1(){
    std::cout << std::left; // left justify output
    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

}

void example2(){
    // assume 4 byte integers
    int x { 2'147'483'647 }; // the maximum value of a 4-byte signed integer
    std::cout << x << '\n';

    x = x + 1; // integer overflow, undefined behavior
    std::cout << x << '\n';


}
void example3(){
     unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';
    unsigned int xu{ 2 };
	unsigned int yu{ 3 };

	std::cout << xu - yu << '\n'; // prints 4294967295 (incorrect!)

    // mixing signe and unsigned intergers
    unsigned int u{ 2 };
	signed int s{ 3 };

	std::cout << u - s << '\n'; // 2 - 3 = 4294967295
}

void example4(){
    std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
	std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";

}

#include <iostream>
#include <limits>

void example5(){
    std::cout<<sizeof(std::size_t)<<"\n";
     std::cout << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << std::numeric_limits<long double>::is_iec559 << '\n';
    int a {5}; //  integer
    double b{5.0}; // flaoting point literal (no suffix means float)
    float c{5.0f}; // f suffic means float type
    
}

void example6(){
    bool b{};
    std::cout << "Enter a boolean value: ";

   // Allow the user to input 'true' or 'false' for boolean values
	// This is case-sensitive, so True or TRUE will not work
	std::cin >> std::boolalpha;
	std::cin >> b;

	// Let's also output bool values as `true` or `false`
	std::cout << std::boolalpha;
	std::cout << "You entered: " << b << '\n';

}

void example7(){
    char name {69};
    std::cout<<name<<"\n";
}

void example8(){
    std::cout<<"Input a keyboard character: ";
    char ch{};
    std::cin >> ch; // ch = 'a', "bcd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    // Note: The following cin doesn't ask the user for input, it grabs queued input!
    std::cin >> ch; // ch = 'b', "cd" is left queued.
    std::cout << "You entered: " << ch << '\n';
}

void print(int x)
{
	std::cout << x << '\n';
}


void example9(){
    int a_eq=2.2;
    // int a_in{2.2};

    double b_eq=2;
    double b_in{2};

    // std::cout<< "print the int values"<< a_eq <<" "<< a_in<<std::endl;//
    std::cerr<< "print the double values"<< b_eq <<" "<< b_in<<std::endl;

    // or we can explicitly convert it using static_cast
    print(static_cast<int>(5.555));


}

int main()
{
   example9();
    return 0;
}