#include<iostream>
#include<ostream>

class Animal{
    int m_id;
    float m_age;
    public:

    Animal(int id, float age):m_age(age),m_id(id){}

    

    

};

std::ostream& operator <<(std::ostream& out, const Animal& Animal){
     out<<" line 1 "<<'\n';
     out<<" line 2 "<<'\n';
     out<<" line 3 "<<'\n';

 return out;
}

int main(){

    Animal a(4,20);
    std::cout<<a;

}