#include <string>

// Note:
// At some point, we decided it's better to return an @std::string.
// But we forgot to update the forward declaration in @"cat.hpp".
std::string mew(void)
{
  return "mew\n";
}