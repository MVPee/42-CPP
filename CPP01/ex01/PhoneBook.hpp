#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int contactCount;
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void addContact(void);
        void displayAllContacts(void);
        void displayContactWithIndex(unsigned int index);
};

#endif