#include <iostream>

int main() {
  // Declare an array of integers
  int numbers[5] = {10, 20, 30, 40, 50};

  // numbers decay into pointer to the first element

  std::cout << "Array elements:" << numbers << std::endl;
}