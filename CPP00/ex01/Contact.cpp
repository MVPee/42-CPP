#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) { return ; }

Contact::~Contact(void) { return ; }

void Contact::setFirstName(std::string firstName) { this->firstName = firstName; }
void Contact::setLastName(std::string lastName) { this->lastName = lastName; }
void Contact::setNickName(std::string nickName) { this->nickName = nickName; }
void Contact::setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
void Contact::setSecret(std::string secret) { this->secret = secret; }

std::string Contact::getFirstName() { return firstName; }
std::string Contact::getLastName() { return lastName; }
std::string Contact::getNickName() { return nickName; }
std::string Contact::getPhoneNumber() { return phoneNumber; }
std::string Contact::getSecret() { return secret; }