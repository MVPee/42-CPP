#include <iostream>
#include <cstring>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    std::string inputUser;

    PhoneBook phoneBook;

    std::cout << "Hello my friends!\nHow Can I help you?" << std::endl;
    while (inputUser != "EXIT") {
        if (inputUser != "EXIT")
            std::cout << "\nADD | SEARCH | EXIT\n" << std::endl;
        
        std::cin >> inputUser;

        if (inputUser == "ADD")
            phoneBook.addContact();
        else if (inputUser == "SEARCH")
            phoneBook.displayContact();
    }
    std::cout << "\nGoodbye!" << std::endl;
    return (0);
}