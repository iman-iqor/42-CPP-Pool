#include"PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contactCount = 0;
}
void PhoneBook::addContact()
{
    if(contactCount < 8)
    {
        std::string input;
        std::cout<<"Enter First Name: ";
        std::getline(std::cin,input);
        contacts[contactCount].setFirstName(input);
        std::cout<<"Enter Last Name: ";
        std::getline(std::cin,input);
        contacts[contactCount].setLastName(input);
        std::cout<<"Enter Nick Name: ";
        std::getline(std::cin,input);
        contacts[contactCount].setNickName(input);
        std::cout<<"Enter Phone Number: ";
        std::getline(std::cin,input);
        contacts[contactCount].setPhoneNumber(input);
        std::cout<<"Enter Darkest Secret: ";
        std::getline(std::cin,input);
        contacts[contactCount].setDarkestSecret(input);
        contactCount++;
        std::cout<<"Contact added successfuly!"<<std::endl;
    }
}
void PhoneBook::displayContacts()
{
    if(contactCount == 0)
    {
        std::cout<<"No contacts to display."<<std::endl;
        return;
    }
    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<" |  Index   |First Name| Last Name| Nick Name |"<<std::endl;
    std::cout<<"---------------------------------------------"<<std::endl;
    for(int i = 0;i< contactCount;i++)
    {
        std::cout<<" |"<<std::setw(10)<<i;
    }

    
}
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
