

#include"static_main.hpp"
#include"iostream"

void incrementFile1() {
    config::count++;
    std::cout << "File1 count: " << config::count << std::endl; // Output: File1 count: 1
}

