#include<iostream>

using namespace std;

class Base{
    public:
    Base(){
        cout<<"Base Ctor"<<"\n";
    }
    
   virtual ~Base(){
        cout<<"Base Dtor"<<"\n";
    }

    virtual void printMe(){
        cout<<"Hi, Base"<<"\n";
    }

};

class Derived:public Base{
    public:
    Derived(){
        cout<<"Dervid ctor"<<"\n";
    }

    ~Derived(){
        cout<<"Dervid dtor"<<"\n";
    }

     void printMe(){
        cout<<"Hi, Dervied"<<"\n";
    }
};
void func(Base* b){
b->printMe();
}

int main(){
    // example 1
    Derived d;
    func(&d);
    cout<<endl;
    

    // example 2
    cout<<"example 2"<<"\n";
    Base *d2=new Derived;
    func(d2);
    delete d2;
    cout<<endl;
    //above example deleteing d2 calling only base constructor not dervied constructor
    // it can be solved by limiting creating base type 
    // and also using virtual base destructor
}