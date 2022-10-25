#include<iostream>

class Base{
    public:
    void method1(){method2();}
    private:
    //added the function
    virtual void method2(){std::cout<<"base method 2 is calledf";};
};
class Derived :public Base{
    private:
    virtual void method2(){
        std::cout<<"derived method 2 is calledf";
    }
};