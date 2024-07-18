# include "Array.hpp"
#include <iostream>

int main(void) {
    try {
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;

        Array<int> arr2(5);
        std::cout << "arr2 size: " << arr2.size() << std::endl;

        Array<int> arr3 = arr2;
        std::cout << "arr3 size: " << arr3.size() << std::endl;

        for (size_t i = 0; i < arr3.size(); ++i) {
            arr3[i] = static_cast<int>(i) * 10;
        }

        std::cout << "arr3 elements:" << std::endl;
        for (size_t i = 0; i < arr3.size(); ++i) {
            std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Try to access to an out off range value:" << std::endl;
        int value = arr3[arr3.size()];
        std::cout << "Value at arr3[" << arr3.size() << "]: " << value << std::endl;

    } catch (std::out_of_range& e) {
        std::cerr << "Out of Range error: " << e.what() << std::endl;
    }

    return (0);
}