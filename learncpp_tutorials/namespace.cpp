#include<iostream>

namespace first{

    namespace second{
        const auto varaible1= 10;
        const auto varaible2=20;
    }

}


int main(){
    std::cout<<" print the variable 1 "<< first::second::varaible1<<'\n';
}