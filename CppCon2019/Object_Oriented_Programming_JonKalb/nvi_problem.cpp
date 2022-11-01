#include<iostream>
#include<string>

using namespace std;

class Animal1{
    public:
    virtual void getSound()=0;

};
class Dog1:public Animal1{
   public:
   void getSound(){
    cout<<"Dog1 making sound bow bow"<<std::endl;
   }
};
class Cat1:public Animal1{
    public:
    void getSound(){
        cout<<"Cat1 making sound meow meow"<<std::endl;
    }
};

class Animal2{
    private:
    virtual std::string getSound()=0;
    public:
    void callGetSound(){
        cout<<"animal"<<getSound()<<"   "<<endl;
    }
};

class Dog2:public Animal2{
    private:
    std::string getSound() {return "bow bow";}
};

class Cat2:public Animal2{
    private:
    string getSound(){return "meow meow";}
};

int main(){
    Dog1 d1;
    Animal1* a1=&d1;
    a1->getSound();

    Dog2 d2;
    Animal2* a2=&d2;
    a2->callGetSound();
}