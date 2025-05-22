/*
 * File: main.cpp
 * Description:
 * Author: Ram Charan Teja Thota
 * Created: 2025-05-22 10:44
 */

#include "function.h"
#include "global.h"
#include <iostream>

int main() {
  global_value += 10;

  update_value(10);

  std::cout << global_value << '\n';
}
