/* #include<iostream>

class Base{
    private:
    int m_base_id;
    public:
    Base(){
        std::cout<<"base constructor is called"<<std::endl;

    }
};

class Dervied: public Base{
    private:
    int m_der_id;
    public:
    Dervied(){
        std::cout<<"derived constructor is called"<<std::endl;
    }
};

int main(){
    Base b;
    Dervied d;
} */

/* // role of constructor in itnializaiton of derived classes
#include<iostream>
class Base
{
public:
    int m_id {};

    Base(int id=0)
        : m_id{ id }
    {
        std::cout<<"base constructor is called"<<std::endl;
    }

    int getId() const { return m_id; }
};

class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0)
        : m_cost{ cost }
    {
         std::cout<<"derived constructor is called"<<std::endl;
    }

    double getCost() const { return m_cost; }
};

int main()
{
Derived derived{ 1.3 }; // use Derived(double) constructor

    return 0;

} */



/* #include<iostream>

class Base
{
public:
     int m_id {};

    Base(int id=0)
        : m_id{ id }
    {
    }

    int getId() const { return m_id; }
}; */

/* class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0)
        : m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};
 */

/* class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0, int id=0)
        // does not work
        : m_cost{ cost }
        , m_id{ id }
    {
    }

    double getCost() const { return m_cost; }
};
 */

/* class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0, int id=0)
        : m_cost{ cost }
    {
        m_id = id;
    }

    double getCost() const { return m_cost; }
}; */

/* #include <iostream>

class Base
{
public:
     int m_id {};

    Base(int id=0)
        : m_id{ id }
    {
        std::cout<<"base constructor is called"<<std::endl;
    }
    ~Base(){
                std::cout<<"base destructor is called"<<std::endl;

    }

    int getId() const { return m_id; }
};

class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0, int id=0)
        : Base{ id } // Call Base(int) constructor with value id!
        , m_cost{ cost }
    {
                std::cout<<"derived constructor is called"<<std::endl;
    }
    ~Derived(){
                std::cout<<"derived destructor is called"<<std::endl;

    }

    double getCost() const { return m_cost; }
};
int main() {
     Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';}
 */

// adding new functionality to a derived class
/* #include <iostream>

class Base
{
protected:
    int m_value {};

public:
    Base(int value)
        : m_value { value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base { value }
    {
    }

    int getValue() const { return m_value; }
};

int main()
{
    Derived derived { 5 };
    std::cout << "derived has value " << derived.getValue() << '\n';

    return 0;
} */

/* #include <iostream>

class Base
{
public:
    Base() { }

     void identify() const { std::cout << "Base::identify()\n"; }
};

class Derived: public Base
{
public:
    Derived() { }

    void identify() const {std::cout << "derived::identify()\n"; }
};

int main()
{
    Base base {};
    base.identify();

    Derived derived {};
    derived.identify();

    return 0;
} */

// hiding functionality

/* #include<iostream>

class Base{
    public:
    int m_value{30};

};

class Derived : public Base
{


public:
     int m_value=20;
};

int main(){
    Derived d;
    
}
 */
// Deleting functions in the derived class
/* #include <iostream>
class Base
{
private:
	int m_value {};

public:
	Base(int value)
		: m_value { value }
	{
	}

	int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base { value }
	{
	}


	int getValue() const = delete; // mark this function as inaccessible
};

int main()
{
	Derived derived { 7 };

    Base b(10);

	// The following won't work because getValue() has been deleted!
	std::cout << static_cast<Base>(derived).getValue();

	return 0;
} */

#include <iostream>

class Base {
public:
    virtual int getValue() const { return 10; } // Base method
};

class Derived : public Base {
public:
    int getValue() const { return 20; } // Overridden method
};

int main() {
    Derived derived;

    // Using static_cast to cast derived to Base reference
    std::cout << static_cast<Base&>(derived).getValue() << std::endl; // Outputs 20

    return 0;
}

