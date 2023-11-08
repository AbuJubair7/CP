#include <iostream>
#include <vector>

// Uncomment the next line to enable debugging features
#define _GLIBCXX_DEBUG

// A simple function that demonstrates vector access
int main() {
    int numbers[5];
    
    // Accessing an element at an out-of-bounds index
    int index = 10;

    #ifdef _GLIBCXX_DEBUG
    std::cout << "Debugging is enabled. Using _GLIBCXX_DEBUG." << std::endl;
    #else
    std::cout << "Debugging is disabled. _GLIBCXX_DEBUG is not defined." << std::endl;
    #endif
    numbers[10] = 100;
    // Attempting to access an element at an out-of-bounds index
    std::cout << "Accessing element at index " << index << ": ";
    std::cout << numbers[index] << std::endl;

    return 0;
}
