#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static bool isNumeric(std::string str) {
    int i = -1;
    while(str[++i])
        if (!isdigit(str[i]))
            return false;
    return true;
}

int main(void)
{
    std::string inputUser;
    int index;
    PhoneBook phoneBook;

    std::cout << RED << "Hello my friends!\n" << GREEN << "How Can I help you?" << RESET << std::endl;
    while (inputUser != "EXIT") {
        if (inputUser != "EXIT")
            std::cout << MAGENTA << "\nADD" << YELLOW << " | " << CYAN << "SEARCH" << YELLOW << " | " << RED << "EXIT\n" << RESET << std::endl;
        
        std::cin >> inputUser;

        if (inputUser == "ADD")
            phoneBook.addContact();
        else if (inputUser == "SEARCH") {
            phoneBook.displayAllContacts();

            index = 8;
            while (index < 0 || index > 7 || !isNumeric(inputUser)) 
            {
                std::cout << CYAN << "Enter a valid index: " << YELLOW;
                std::cin >> inputUser;
                if (inputUser == "EXIT")
                    return (std::cout << "\nGoodbye!" << std::endl, 0);
                index = atoi(inputUser.c_str());
            }
            phoneBook.displayContactWithIndex((unsigned int)index);
        }
    }
    std::cout << RED << "\nGoodbye!" << RESET << std::endl;
    return (0);
}