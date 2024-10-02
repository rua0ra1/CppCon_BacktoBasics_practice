/* restting a class back to default state */
/* 
#include <iostream>

class Calc
{
private:
    int m_value{};

public:
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    int getValue() const { return m_value; }

    void reset() { *this = {}; }
};


int main()
{
    Calc calc{};
    calc.add(5).sub(3).mult(4);

    std::cout << calc.getValue() << '\n'; // prints 8

    calc.reset();

    std::cout << calc.getValue() << '\n'; // prints 0

    return 0;
} */

/* nested types (member types) */
/* 
#include <iostream>


class Fruit
{

    public:
    enum Type
    {
        apple,
        banana,
        cherry

    };
    private:
    Type m_type;
    int m_percentageEaten{0};
    public:
	Fruit(Type type) :
		m_type { type }
	{
	}

	Type getType() { 
        return m_type; 
        }
	int getPercentageEaten() { 
        return m_percentageEaten; 
        }

	bool isCherry() { 
        return m_type == Type::cherry; }

};

int main(){
    Fruit apple { Fruit::apple };

	if (apple.getType() == Fruit::apple)
		std::cout << "I am an apple";
	else
		std::cout << "I am not an apple";

	return 0;
}; */

// Static member variables
/* #include<iostream>

struct Something{
  const static int s_value{2}; //now static
};

//int Something::s_value{1};

int main(){
    Something first{};
    Something second{};

    first.s_value=2;

    std::cout<<first.s_value<<'\n';
    std::cout<<second.s_value<<'\n';


} */

/* #include <iostream>

class Something{

    private:
    static int s_value;

    public:
    static int getValue(){return s_value;} // static member function

};

int Something::s_value {2};


int main(){
    std::cout<<Something::getValue()<<'\n';
} */

// 
/* #include <iostream>

struct Chars
{
    char first{};
    char second{};
    char third{};
    char fourth{};
    char fifth{};
};

class MyClass
{
private:
    static Chars generate()
    {
        Chars c{}; // create an object
        c.first = 'a'; // fill it with values however you like
        c.second = 'e';
        c.third = 'i';
        c.fourth = 'o';
        c.fifth = 'u';

        return c; // return the object
    }

public:
	static inline Chars s_mychars { generate() }; // copy the returned object into s_mychars
};

int main()
{
    std::cout << MyClass::s_mychars.third; // print i

    return 0;
} */
#include<iostream>
class Animal{
    private:
    int m_id;
    public:
    Animal(int id):m_id(id){}
    void Addnum(Animal& a_in){
        std::cout<<"sum is "<<(this->m_id+a_in.m_id)<<'\n';

    }
};

int main(){
    Animal a1(2);
    Animal a2(3);

    a1.Addnum(a2);
}