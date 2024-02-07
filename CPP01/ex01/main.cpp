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

    std::cout << "Hello my friends!\nHow Can I help you?" << std::endl;
    while (inputUser != "EXIT") {
        if (inputUser != "EXIT")
            std::cout << "\nADD | SEARCH | EXIT\n" << std::endl;
        
        std::cin >> inputUser;

        if (inputUser == "ADD")
            phoneBook.addContact();
        else if (inputUser == "SEARCH") {
            phoneBook.displayAllContacts();

            index = 8;
            while (index < 0 || index > 7 || !isNumeric(inputUser)) 
            {
                std::cout << "Enter a valid index: ";
                std::cin >> inputUser;
                index = atoi(inputUser.c_str());
            }
            phoneBook.displayContactWithIndex((unsigned int)index);
        }
    }
    std::cout << "\nGoodbye!" << std::endl;
    return (0);
}