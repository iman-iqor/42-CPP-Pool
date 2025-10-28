#include "PhoneBook.hpp"

int main()
{
   PhoneBook phoneBook;
   std::string command;
   while(1)
   {
        std::cout<<"Enter a comand (ADD,SEARCH,EXIT)"<<std::endl;
        std::getline(std::cin,command);
        if(command == "ADD")
        {
            phoneBook.addContact();
        
        }
        else if(command == "SEARCH")
        {
            phoneBook.displayContacts();
        
        }
        else if(command == "EXIT")
        {
            std::cout<<"EXITING THE PHONEBOOK"<<std::endl;
            break;

        }
        else
        {
            std::cout<<"INVALID COMMAND, PLEASE ENTER A VALID COMMAND"<<std::endl;  
        }
   }
   return 0;
}