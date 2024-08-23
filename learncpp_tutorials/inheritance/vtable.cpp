#include<iostream>

struct Base{
    virtual void DoSmth() const{
        std::cout<<"base class is callde"<<"\n";
    }
};

struct Derived:public Base{
    void DoSmth() const override {
        std::cout<<"derived class is callde"<<"\n";
    }
};

int main(){
    const Base base{};
    Derived der{};
    const Base& base_ref=base;

    base_ref.DoSmth();

}