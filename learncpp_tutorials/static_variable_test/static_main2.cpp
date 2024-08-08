
#include"static_main.hpp"
#include"iostream"

void incrementFile2() {
    config::count++;
    std::cout << "File2 count: " << config::count << std::endl; // Output: File1 count: 1
}