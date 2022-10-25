// C++ program to demonstrate what is object slicing
#include<iostream>
#include<string>
using namespace std;
struct Animal{
    string name;
    void display(){
        cout<<"name is"<<name<<endl;
    }

};

struct rat1:public Animal{
    string name="r1";
    int length=20;
    int speed=300;
    void display(){
        cout<<"name is"<<name<<endl;
    }
};

struct rat2:public Animal{
    string name="r2";
    int length=20;
    int weight=150;
    void display(){
        cout<<"name is"<<name<<endl;
    }
};

int main(){
    rat1 r1;
    rat2 r2;

    Animal *a1=&r1;
    Animal *a2=&r2;

    *a1=*a2;
    // it is expect that a1 should point to r2 object and should have name , length , weight as 
    // member variables but only variables and function in base class are only copied
    cout<<"name is -------"<<a1->name;
}