
#include<iostream>

class Animal {
public:
    // Constructor with an ID parameter
    Animal(int id) : id_(id) {std::cout<<"normal cosntructor is called"<<"\n";}

    // Copy constructor
    Animal(const Animal& rhs) {
        // Copy the id_ from rhs to the new object
        id_ = rhs.id_;
        std::cout << "Copy constructor called, ID: " << id_ << std::endl;
    }

private:
    int id_;  // Member variable to store ID
};

int main(){

    Animal a1(10);
    Animal a2=a1;

}