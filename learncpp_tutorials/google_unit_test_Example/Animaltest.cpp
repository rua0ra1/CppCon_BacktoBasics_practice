#include"Animal.hpp"
#include<gtest/gtest.h>

TEST(AnimalTest, animalID){

    Animal a;
    a.setId(10);

    EXPECT_EQ(a.getId(),10);

}