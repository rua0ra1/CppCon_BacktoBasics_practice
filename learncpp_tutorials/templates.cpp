#include<iostream>

template <typename T>
class Calculator{
    public:
    T sumofTwoNumber(T num1, T num2){
        return num1+num2;
    }
};

int main(){
    Calculator<float> f;
    auto sum=f.sumofTwoNumber(0.5,0.6);
    std::cout<<"the sum of floats"<<sum<<"\n";

    Calculator<std::string> s;
    auto string_sum=s.sumofTwoNumber("0.5","0.6");
    std::cout<<"the sum of floats"<<string_sum<<"\n";



}