#include"animal.hpp"
#include<iostream>

namespace Animal
{
    namespace Library
    {
        // Implementation of makeSound
        void cow::makeSound() {
            // For example, a cow might "moo"
            std::cout << "Moo!" << std::endl;
        }

        // Implementation of getId
        int cow::getId() {
            return id_;
        }

        // Implementation of setId
        void cow::setId(int id) {
            id_ = id;
        }

       
        
    } // namespace name
    
    
} // namespace Animal
