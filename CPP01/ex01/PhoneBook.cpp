#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    contactCount = 0;
    return ;
}

PhoneBook::~PhoneBook(void) { return ; }

void PhoneBook::addContact(void) {
    Contact newContact;
    if (contactCount >= 8)
        contactCount = 0;
    std::string input;
    
    std::cout << "FirstName: ";
    std::cin >> input;
    newContact.setFirstName(input);

    std::cout << "LastName: ";
    std::cin >> input;
    newContact.setLastName(input);

    std::cout << "NickName: ";
    std::cin >> input;
    newContact.setNickName(input);

    std::cout << "PhoneNumber: ";
    std::cin >> input;
    newContact.setPhoneNumber(input);

    std::cout << "Secret: ";
    std::cin >> input;
    newContact.setSecret(input);

    contacts[contactCount] = newContact;
    std::cout << "\nContact Created succesfully!" << std::endl;
    contactCount++;
}

void PhoneBook::displayContact(void) {
    std::string temp;

    for (int i = 0; i < 8; i++) {
        std::cout << i << " | " + contacts[i].getFirstName() + " | " + contacts[i].getLastName() + " | " + contacts[i].getNickName() << std::endl;
    }
}