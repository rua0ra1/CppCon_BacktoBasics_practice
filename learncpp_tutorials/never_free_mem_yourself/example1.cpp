#include <iostream>

int main(){
    int size=2;
    int* ptr= nullptr;

    {
        int array[size];
        array[0]=42;
        array[1]=23;

        ptr=array;
        std::cout<<"Before stact cleanup. \n";
        for (int i=0;i <size;++i){
            std::cout<<ptr[i]<<std::endl;
        }
    }

    // code below leads to undefined behaviour
    std::cout<<"After stack cleanup. \n";
    for (int i=0; i<size;++i){
        std::cout<<ptr[i]<<std::endl;
    }
}