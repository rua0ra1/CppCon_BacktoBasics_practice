/*
 * File: compiler_optimisation_levels.cpp
 * Description: 
 * Author: Ram Charan Teja Thota
 * Created: 2025-05-22 10:14
 */

/*
1) there four optimisation levels in gcc
   -O,-O1, -O2 ,-O3
2) -m options are defined of the x86 family of computers
 */

#include <vector>

int main() {
  // create a vector of 2^28 elemetns
  auto num_elements = 1 << 28;
  std::vector<int> vector(num_elements);

  // modulo each value by 20
  for (auto &value : vector) {
    value %= 20;
  }
}

