/* unscoped enumeration named color */

/* enum Color{
    red,
    green,
    blue,
};

int main()
{
    Color apple{red};
    Color shirt{green };
} */
// Commonly defined enumerations include days of the week, the cardinal directions, and the suits in a deck
/* enum FileReadResult{
      readResultSuccess,
    readResultErrorFileOpen,
    readResultErrorFileRead,
    readResultErrorFileParse,

};

FileReadResult readFileContents()
{
    if (!openFile())
        return readResultErrorFileOpen;
    if (!readFile())
        return readResultErrorFileRead;
    if (!parseFile())
        return readResultErrorFileParse;

    return readResultSuccess;
}

if (readFileContents() == readResultSuccess)
{
    // do something
}
else
{
    // print error message
} */

// the enum is defined in the global namespace
/* enum Color // this enum is defined in the global namespace
{
    red, // so red is put into the global namespace
    green,
    blue,
};

int main()
{
    Color apple { red }; // my apple is red

    return 0;
} */

// unscoped enumerations will implicitly to integral values
/* #include <iostream>

enum Color
{
    black, // assigned 0
    red, // assigned 1
    blue, // assigned 2
    green, // assigned 3
    white, // assigned 4
    cyan, // assigned 5
    yellow, // assigned 6
    magenta, // assigned 7
};

int main()
{
    Color shirt{ blue };

    std::cout << "Your shirt is " << shirt << '\n'; // what does this do?

    return 0;
}
 */

// explicitly specify an underlying type for an enumeration
/* #include<cstdint>
#include<iostream>

//use an 8 bit integer as enum underlying type
enum Color: std::int8_t
{
    black,
    red,
    blue,
};
int main()
{
    Color c{ black };
    std::cout << sizeof(c) << '\n'; // prints 1 (byte)

    return 0;
} */

// getting an enumeration from a string
/* #include <iostream>
#include <optional> // for std::optional
#include <string>
#include <string_view>

enum Pet
{
    cat,   // 0
    dog,   // 1
    pig,   // 2
    whale, // 3
};

constexpr std::string_view getPetName(Pet pet)
{
    switch (pet)
    {
    case cat:   return "cat";
    case dog:   return "dog";
    case pig:   return "pig";
    case whale: return "whale";
    default:    return "???";
    }
}

constexpr std::optional<Pet> getPetFromString(std::string_view sv)
{
    if (sv == "cat")   return cat;
    if (sv == "dog")   return dog;
    if (sv == "pig")   return pig;
    if (sv == "whale") return whale;

    return {};
}

int main()
{
    std::cout << "Enter a pet: cat, dog, pig, or whale: ";
    std::string s{};
    std::cin >> s;

    std::optional<Pet> pet { getPetFromString(s) };

    if (!pet)
        std::cout << "You entered an invalid pet\n";
    else
        std::cout << "You entered: " << getPetName(*pet) << '\n';

    return 0;
} */

// scope enumeration key words enum class

/* #include<iostream>
int main(){
    enum class Color
    {
        red,
        blue,
    };
    enum class Fruit
    {
        banana, // banana is considered part of Fruit's scope region
        apple,
    };

    Color color { Color::red }; // note: red is not directly accessible, we have to use Color::red
    Fruit fruit { Fruit::banana }; // note: banana is not directly accessible, we have to use Fruit::banana

    if (color == fruit) // compile error: the compiler doesn't know how to compare different types Color and Fruit
        std::cout << "color and fruit are equal\n";
    else
        std::cout << "color and fruit are not equal\n";

    return 0;

} */

/* // struct
#include<iostream>
struct Employee{
    int id {};
    int age {};
    double wage{};
};

int main(){
    Employee e{};

    std::cout << e.age<<e.id<<e.wage<<'\n';
} */

// struct aggregate initalization
// const structs
/* struct Rectangle
{
    double length {};
    double width {};
};

int main()
{
    const Rectangle unit { 1.0, 1.0 };
    const Rectangle zero {};



    return 0;
} */
// value intialization possibilties

/* #include <iostream>
struct Something
{
    int x;       // no default initialization value (bad)
    int y {};    // value-initialized by default
    int z { 2 }; // explicit default value
};

std::ostream& operator<<(std::ostream& out, const Something& f)
{
    out << f.x << ' ' << f.y << ' ' << f.z;
    return out;
}

int main()
{
    Something s1;             // No initializer list: s1.x is uninitialized, s1.y and s1.z use defaults
    Something s2 { 5, 6, 7 }; // Explicit initializers: s2.x, s2.y, and s2.z use explicit values (no default values are used)
    Something s3 {};          // Missing initializers: s3.x is value initialized, s3.y and s3.z use defaults
    
     std::cout << s1 << '\n';
    std::cout << s2 << '\n';
    std::cout << s3 << '\n';
    return 0;
} */

// always provide default values for your members

#include <iostream>
struct Fraction
{
	int numerator{}; // we should use { 0 } here, but for the sake of example we'll use value initialization instead
	int denominator { 1 };
};

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << f.numerator << ' ' << f.denominator ;
    return out;
}

int main()
{
	Fraction f1;          // f1.numerator value initialized to 0, f1.denominator defaulted to 1
	Fraction f2 {};       // f2.numerator value initialized to 0, f2.denominator defaulted to 1
	Fraction f3 { 6 };    // f3.numerator initialized to 6, f3.denominator defaulted to 1
	Fraction f4 { 5, 8 }; // f4.numerator initialized to 5, f4.denominator initialized to 8

    std::cout<< f1 << '\n';
    std::cout<<f2<<'\n';
    std::cout<<f3<<'\n';
    std::cout<<f4<<'\n';
    


	return 0;
}
