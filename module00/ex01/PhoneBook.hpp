#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include"Contact.hpp"


class PhoneBook{
    private:
        Contact contacts[8];
        int contactCount;
        int oldestIndex;
    public:
        PhoneBook();
        void addContact();
        void displayContacts() ;
        int emptyFieldCheck(std::string str);
        int is_valid(std::string str);



};

#endif