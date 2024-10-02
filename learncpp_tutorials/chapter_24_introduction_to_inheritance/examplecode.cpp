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

#include <iostream>

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
