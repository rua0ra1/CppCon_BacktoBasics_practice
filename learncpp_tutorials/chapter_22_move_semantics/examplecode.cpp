// RAII in action

/* #include<iostream>

template<typename T>
class Autoptr
{
  T* m_ptr{};
  public:
   Autoptr(T* ptr=nullptr):m_ptr(ptr){
    std::cout<<" autoptr is constructor is callled \n";

    
   }
   // The destructor will make sure it gets deallocated
	~Autoptr()
	{
        std::cout<<" autoptr is destructor is callled \n";
		delete m_ptr;
	}

    // Overload dereference and operator-> so we can use Auto_ptr1 like m_ptr.
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};


//sample class to prove the above works
class Resource
{  
     int m_id= 10;
    public:
     Resource(){std::cout <<"Resource acquired \n";}
     ~Resource() { std::cout << "Resource destroyed\n"; }

     int getId(){return m_id;}
     void setId(int id){m_id=id;}

    

};

int main()
{
	Autoptr<Resource> res(new Resource()); // Note the allocation of memory here

        // ... but no explicit delete needed

	// Also note that we use <Resource>, not <Resource*>
        // This is because we've defined m_ptr to have type T* (not T)
    res->getId();
    (*res).setId(10);

	return 0;
} */ // res goes out of scope here, and destroys the allocated Resource for

// move semantics

/* #include <iostream>

template <typename T>
class Auto_ptr2
{
	T* m_ptr {};
public:
	Auto_ptr2(T* ptr=nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr2()
	{
		delete m_ptr;
	}

	// A copy constructor that implements move semantics
	Auto_ptr2(Auto_ptr2& a) // note: not const
	{
		// We don't need to delete m_ptr here.  This constructor is only called when we're creating a new object, and m_ptr can't be set prior to this.
		m_ptr = a.m_ptr; // transfer our dumb pointer from the source to our local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
	}

	// An assignment operator that implements move semantics
	Auto_ptr2& operator=(Auto_ptr2& a) // note: not const
	{
		if (&a == this)
			return *this;

		delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
		m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	Auto_ptr2<Resource> res1(new Resource());
	Auto_ptr2<Resource> res2; // Start as nullptr

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	res2 = res1; // res2 assumes ownership, res1 is set to null

	std::cout << "Ownership transferred\n";

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	return 0;
} */

// comparing lvalue refernece and rvalue reference
/* #include <iostream>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main() {
    const Resource& res = Resource();  // Const l-value reference to a temporary object
    // The lifetime of the temporary is extended to the scope of res
    std::cout << "Temporary object's lifetime extended!\n";
    
    return 0;
} */
/* 
#include <iostream>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

Resource&& getTemporaryResource() {
    return Resource();  // Returning a temporary r-value
}

int main() {
    std::cout<<"Main started: \n";
   auto&&ref{5};
   std::cout<<"Main ended: \n";
} */

// R value references as function parameters
/* #include <iostream>

void fun(const int& lref) // l-value arguments will select this function
{
	std::cout << "l-value reference to const: " << lref << '\n';
}

void fun(int&& rref) // r-value arguments will select this function
{
	std::cout << "r-value reference: " << rref << '\n';
}

int main()
{
	int x{ 5 };
	fun(x); // l-value argument calls l-value version of function
	fun(5); // r-value argument calls r-value version of function

    int&& ref{5};

    fun(ref);

	return 0;
}
 */

// Recapping copy constructor and copy assignment operator

/* #include <iostream>

template<typename T>
class Auto_ptr3
{
	T* m_ptr {};
public:
	Auto_ptr3(T* ptr = nullptr)
		: m_ptr { ptr }
	{
	}

	~Auto_ptr3()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3(const Auto_ptr3& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3& operator=(const Auto_ptr3& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr3<Resource> generateResource()
{
	Auto_ptr3<Resource> res{new Resource};
	return res; // this return value will invoke the copy constructor
}

int main()
{
	Auto_ptr3<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the copy assignment

	return 0;
} */

// Move semantics and Move Assignment
/* 
#include <iostream>

template<typename T>
class Auto_ptr4
{
	T* m_ptr {};
public:
	Auto_ptr4(T* ptr = nullptr)
		: m_ptr { ptr }
	{
	}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4(Auto_ptr4&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // we'll talk more about this line below
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // we'll talk more about this line below

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr4<Resource> generateResource()
{
	Auto_ptr4<Resource> res{new Resource};
	return res; // this return value will invoke the move constructor
}

int main()
{
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment

	return 0;
} */

// simple move and copy constructor adn assignemnt operator
/* #include <iostream>

class MyClass {
public:
    int* data;

    // Constructor
    MyClass(int value) {
        data = new int(value);  // Dynamically allocate an integer
        std::cout << "Constructor: Resource allocated with value " << *data << "\n";
    }

    // Destructor
    ~MyClass() {
        if (data) {
            std::cout << "Destructor: Resource freed with value " << *data << "\n";
            delete data;  // Free dynamically allocated memory
        } else {
            std::cout << "Destructor: No resource to free\n";
        }
    }

    // Copy constructor (deep copy)
    MyClass(const MyClass& other) {
        data = new int(*other.data);  // Allocate new memory and copy the value
        std::cout << "Copy Constructor: Resource copied with value " << *data << "\n";
    }

    // Move constructor (transfer ownership)
    MyClass(MyClass&& other) noexcept
        : data(other.data)  // Steal the resource (ownership)
    {
        other.data = nullptr;  // Nullify the source object to avoid double deletion
        std::cout << "Move Constructor: Resource moved\n";
    }

    // Copy assignment operator (deep copy)
    MyClass& operator=(const MyClass& other) {
        if (this == &other)  // Self-assignment check
            return *this;

        delete data;  // Free existing resource
        data = new int(*other.data);  // Allocate new memory and copy the value
        std::cout << "Copy Assignment: Resource copied with value " << *data << "\n";

        return *this;
    }

    // Move assignment operator (transfer ownership)
    MyClass& operator=(MyClass&& other) noexcept {
        if (this == &other)  // Self-assignment check
            return *this;

        delete data;  // Free existing resource
        data = other.data;  // Steal the resource (ownership)
        other.data = nullptr;  // Nullify the source object to avoid double deletion
        std::cout << "Move Assignment: Resource moved\n";

        return *this;
    }
};

int main() {
    MyClass obj1(10);            // Constructor called
    MyClass obj2 = obj1;         // Copy constructor called

    MyClass obj3(20);            // Constructor called
    obj3 = obj1;                 // Copy assignment operator called

    MyClass obj4 = MyClass(30);  // Move constructor called (temporary r-value)

    MyClass obj5(40);            // Constructor called
    obj5 = std::move(obj4);      // Move assignment operator called

    return 0;
}
 

// performance difference between copying and moving
 #include <algorithm> // for std::copy_n
#include <chrono> // for std::chrono functions
#include <iostream>

// Uses the above DynamicArray class

template <typename T>
class DynamicArray
{
private:
	T* m_array {};
	int m_length {};

public:
	DynamicArray(int length)
		: m_array { new T[length] }, m_length { length }
	{
	}

	~DynamicArray()
	{
		delete[] m_array;
	}

	// Copy constructor
	DynamicArray(const DynamicArray &arr)=delete;
		: m_length { arr.m_length }
	{
		m_array = new T[m_length];
		std::copy_n(arr.m_array, m_length, m_array); // copy m_length elements from arr to m_array
	} 

	// Copy assignment
	DynamicArray& operator=(const DynamicArray &arr)=delete;
 	{
		if (&arr == this)
			return *this;

		delete[] m_array;

		m_length = arr.m_length;
		m_array = new T[m_length];

		std::copy_n(arr.m_array, m_length, m_array); // copy m_length elements from arr to m_array

		return *this;
	} 

    	// Move constructor
	DynamicArray(DynamicArray &&arr) noexcept
		:  m_array(arr.m_array), m_length(arr.m_length)
	{
		arr.m_length = 0;
		arr.m_array = nullptr;
	}

	// Move assignment
	DynamicArray& operator=(DynamicArray &&arr) noexcept
	{
		if (&arr == this)
			return *this;

		delete[] m_array;

		m_length = arr.m_length;
		m_array = arr.m_array;
		arr.m_length = 0;
		arr.m_array = nullptr;

		return *this;
	}

	int getLength() const { return m_length; }
	T& operator[](int index) { return m_array[index]; }
	const T& operator[](int index) const { return m_array[index]; }

};

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using Clock = std::chrono::high_resolution_clock;
	using Second = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<Clock> m_beg { Clock::now() };

public:
	void reset()
	{
		m_beg = Clock::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
	}
};

// Return a copy of arr with all of the values doubled
DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int> &arr)
{
	DynamicArray<int> dbl(arr.getLength());
	for (int i = 0; i < arr.getLength(); ++i)
		dbl[i] = arr[i] * 2;

	return dbl;
}

int main()
{
	Timer t;

	DynamicArray<int> arr(1000000);

	for (int i = 0; i < arr.getLength(); i++)
		arr[i] = i;

	arr = cloneArrayAndDouble(arr);

	std::cout << t.elapsed();
} */

//   std::unique_ptr properly implements move semantics
/* #include <iostream>
#include <memory> // for std::unique_ptr
#include <utility> // for std::move

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	std::unique_ptr<Resource> res1{ new Resource{} }; // Resource created here
	std::unique_ptr<Resource> res2{}; // Start as nullptr

	std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

	// res2 = res1; // Won't compile: copy assignment is disabled
	res2 = std::move(res1); // res2 assumes ownership, res1 is set to null

	std::cout << "Ownership transferred\n";

	std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

	return 0;
}  */// Resource destroyed 

// std::make_unqiue pointer
/* #include <memory> // for std::unique_ptr and std::make_unique
#include <iostream>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};


int main()
{
	// Create a single dynamically allocated Fraction with numerator 3 and denominator 5
	// We can also use automatic type deduction to good effect here
	auto f1{ std::make_unique<Fraction>(3, 1) };
	std::cout << *f1 << '\n';

	// Create a dynamically allocated array of Fractions of length 4
	auto f2{ std::make_unique<Fraction[]>(4) };
	std::cout << f2[0] << '\n';

	return 0;
} */

//

// return std::unique_pter from a function
/* #include<iostream>
#include <memory> // for std::unique_ptr

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

std::unique_ptr<Resource> createResource()
{
     return std::make_unique<Resource>();
}

int main()
{
    auto ptr{ createResource() };

    // do whatever

    return 0;
} */

// circular dependancy
/* #include <iostream>
#include <memory> // for std::shared_ptr
#include <string>

class Person
{
	std::string m_name;
	std::shared_ptr<Person> m_partner; // initially created empty

public:

	Person(const std::string &name): m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;
	}
};

int main()
{
	auto lucy_ptr { std::make_shared<Person>("Lucy") }; // create a Person named "Lucy"
	auto ricky_ptr { std::make_shared<Person>("Ricky") }; // create a Person named "Ricky"

	partnerUp(lucy_ptr, ricky_ptr); // Make "Lucy" point to "Ricky" and vice-versa

	return 0;
} */

// weak pointer
#include <iostream>
#include <memory> // for std::shared_ptr and std::weak_ptr
#include <string>

class Person
{
	std::string m_name;
	std::weak_ptr<Person> m_partner; // note: This is now a std::weak_ptr

public:

	Person(const std::string &name): m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;
	}
};

int main()
{
	auto lucy { std::make_shared<Person>("Lucy") };
	auto ricky { std::make_shared<Person>("Ricky") };

	partnerUp(lucy, ricky);

	return 0;
}