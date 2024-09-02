#include <iostream>
#include<memory>

class Animal{
    public:
   Animal(std::string name): name_(name){
    std::cout<< name_<<" object created "<<std::endl;
   }

   ~Animal(){
    std::cout<<name_<< " object destroyed "<<std::endl;
   }

   private:
   std::string name_;
};

int main(){

   

    auto animal_ptr=std::make_unique<Animal>("Lion");

    animal_ptr.reset(new Animal("Tiger"));


    std::cout<<"end of the main"<<std::endl;




}