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

static bool cmpCase(std::string str, std::string str2) {
    int i = -1;

    if (str == "")
        return (true);
    while(str[++i])
        if (tolower(str[i]) != tolower(str2[i]))
            return (true);
    return (false);
}

int main(void)
{
    std::string inputUser;
    int index;
    PhoneBook phoneBook;

    inputUser.assign("");
    std::cout << RED << "Hello my friends!\n" << GREEN << "How Can I help you?" << RESET << std::endl;
    while (cmpCase(inputUser, "EXIT")) {
        if (inputUser != "EXIT")
            std::cout << MAGENTA << "\nADD" << YELLOW << " | " << CYAN << "SEARCH" << YELLOW << " | " << RED << "EXIT\n" << RESET << std::endl;
        
        std::cin >> inputUser;

        if (!cmpCase(inputUser, "ADD"))
            phoneBook.addContact();
        else if (!cmpCase(inputUser, "SEARCH")) {
            phoneBook.displayAllContacts();

            index = 8;
            while (index < 0 || index > 7 || !isNumeric(inputUser)) 
            {
                std::cout << CYAN << "Enter a valid index: " << YELLOW;
                std::cin >> inputUser;
                if (!cmpCase(inputUser, "EXIT"))
                    return (std::cout << RED << "\nGoodbye!" << RESET << std::endl, 0);
                index = atoi(inputUser.c_str());
            }
            phoneBook.displayContactWithIndex((unsigned int)index);
        }
    }
    std::cout << RED << "\nGoodbye!" << RESET << std::endl;
    return (0);
}