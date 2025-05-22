/*
 * File: name.cpp
 * Description:
 * Author: Ram Charan Teja Thota
 * Created: 2025-05-22 12:08
 */

#include <algorithm>
#include <array>
#include <iostream>

class animalManager {
 private:
  /* data */
 public:
  animalManager(/* args */);
  ~animalManager();
};

animalManager::animalManager(/* args */) {}

animalManager::~animalManager() {}

int main() {
  std::array<int, 5> my_array = {1, 3, 4, 5, 5};
  my_array[2] = 3;
}
