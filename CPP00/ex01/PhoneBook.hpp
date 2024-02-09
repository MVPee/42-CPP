#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m" 
#define MAGENTA "\033[1m\033[35m" 
#define CYAN    "\033[1m\033[36m" 
#define YELLOW  "\033[1m\033[33m"

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