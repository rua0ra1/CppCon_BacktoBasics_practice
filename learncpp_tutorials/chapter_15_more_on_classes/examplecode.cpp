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
};