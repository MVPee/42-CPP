#include <iostream>
#include "PhoneBook.hpp"

static bool isNumeric(std::string str) {
    int i = -1;
    while(str[++i])
        if (!isdigit(str[i]))
            return false;
    return true;
}

PhoneBook::PhoneBook(void) {
    contactCount = 0;
    for (unsigned int i = 0; i < 8; i++) {
        contacts[i].setFirstName("NONE");
        contacts[i].setLastName("NONE");
        contacts[i].setNickName("NONE");
        contacts[i].setPhoneNumber("NONE");
        contacts[i].setSecret("NONE");
    }
}

PhoneBook::~PhoneBook(void) { return ; }

void PhoneBook::addContact(void) {
    std::string input;

    if (contactCount >= 8)
        contactCount = 0;
    
    std::cout << MAGENTA << "FirstName: " << YELLOW;
    std::cin >> input;
    if (std::cin.eof())
        return ;
    contacts[contactCount].setFirstName(input);

    std::cout << MAGENTA << "LastName: " << YELLOW;
    std::cin >> input;
    if (std::cin.eof())
        return ;
    contacts[contactCount].setLastName(input);

    std::cout << MAGENTA << "NickName: " << YELLOW;
    std::cin >> input;
    if (std::cin.eof())
        return ;
    contacts[contactCount].setNickName(input);

    input.assign("a");
    while(!isNumeric(input))
    {
        std::cout << MAGENTA << "PhoneNumber: " << YELLOW;
        std::cin >> input;
        if (std::cin.eof())
            return ;
        contacts[contactCount].setPhoneNumber(input);
    }

    std::cout << MAGENTA << "Secret: " << YELLOW;
    std::cin >> input;
    if (std::cin.eof())
        return ;
    contacts[contactCount].setSecret(input);

    std::cout << GREEN << "\nContact Created succesfully!" << RESET << std::endl;
    contactCount++;
}

static std::string toTenChar(std::string str) {
    std::string spaces(10, ' ');

    if (str.size() > 10)
        return str.substr(0, 9) + ".";
    return spaces.substr(0, 10 - str.size()) + str;
}

void PhoneBook::displayAllContacts(void) {
    for (int i = 0; i < 8; i++)
        std::cout << YELLOW << "         " << i << "|" << toTenChar(contacts[i].getFirstName()) << "|" << toTenChar(contacts[i].getLastName()) << "|" << toTenChar(contacts[i].getNickName()) << RESET << std::endl;
}

void PhoneBook::displayContactWithIndex(unsigned int index) {
    std::cout << "\nFirstname: " + contacts[index].getFirstName() << std::endl;
    std::cout << "Lastname: " + contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " + contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " + contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " + contacts[index].getSecret() << std::endl;
}