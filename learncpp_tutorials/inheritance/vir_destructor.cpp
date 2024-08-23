#include<iostream>

struct Base{
    virtual ~Base(){
        std::cout<<"Base cleanup"<<std::endl;
    }
};

struct Derived:public Base{
    ~Derived() override{
        std::cout<<"Derived cleanup"<<std::endl;
    }
};

int main(){
    Base *ptr=new Derived;

    delete ptr;
}

