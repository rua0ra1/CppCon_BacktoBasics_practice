#include<iostream>

using namespace std;

class Base{
    public:
    Base(){
        cout<<"Base Ctor"<<"\n";
    }
    
  

    virtual void printMe(){
        cout<<"Hi, Base"<<"\n";
    }
    protected:
     virtual ~Base(){
        cout<<"Base Dtor"<<"\n";
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

/* limitations of nonvirtual inheritance */
class Base1{
    
    public:
    Base1(){
        
    }
    Base1(int a,int b):A(a),B(b){
        cout<<"Base Ctor"<<"\n";
    }

    void Print(){
        cout<<"getA:"<<getA()<<endl;
        cout<<"getB:"<<getB()<<endl;

    }

    int getA(){return A;}
    int getB(){return B;}

    int A,B;


};

class Derived1:public Base1{
    public:

    Derived1(){
    }

    void PrintCAller(){
        Print();
    }

    int getA(){return A*5;}
    int getB(){return B*5;}
};

int main(){
    Derived d;
    d.printMe();
    cout<<endl;

    Derived1  d1;
    d1.PrintCAller();
}