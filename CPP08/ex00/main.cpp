# include <iostream>
# include <vector>
# include <list>
# include "easyfind.hpp"

int main(void) {
    int vec_arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(vec_arr, vec_arr + 5);
    
    int lst_arr[] = {10, 20, 30, 40, 50};
    std::list<int> lst(lst_arr, lst_arr + 5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 4);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 40);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 0);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
