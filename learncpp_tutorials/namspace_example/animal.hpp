#pragma once

namespace Animal{
    namespace Library{

        class cow{
            public:
            void makeSound();

            int getId();
            void setId (int id );

            private:
            int id_;

        };
    }

}