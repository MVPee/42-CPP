#include <iostream>
#include <string>

int main() {
    //STR
    std::string str = "HI THIS IS BRAIN";
    //Pointeur
    std::string* stringPTR = &str;
    //Reference
    std::string& stringREF = str;

    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "The value of the string variable: " << str << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
    return 0;
}
