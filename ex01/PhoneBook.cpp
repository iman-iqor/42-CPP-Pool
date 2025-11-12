#include "PhoneBook.hpp"
#include <iomanip>
#include <stdlib.h>

PhoneBook::PhoneBook()
{
    contactCount = 0;
}
int PhoneBook::getContactCount()
{
    return contactCount;
}
int PhoneBook::emptyFieldCheck(std::string str)
{
    size_t i = 0;
    while (i < str.length() && str[i] == ' ')
    {
        i++;
    }
    if (i == str.length())
        return 1;
    return 0;
}
int PhoneBook::is_valid(std::string str)
{
    if (str.empty())
        return 0;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

void PhoneBook::addContact()
{
    std::string input;
    int index;

    if (contactCount < 8)
        index = contactCount;
    else
    {
        index = 0;
        std::cout << "PhoneBook full. Replacing the first contact with the new one." << std::endl;
    }

    while (true)
    {
        std::cout << "Enter First Name: ";
        if (std::getline(std::cin, input).eof())
            return;
        if (input.empty() || PhoneBook::emptyFieldCheck(input))
        {
            std::cout << "First name cannot be empty. Please try again." << std::endl;
            continue;
        }
        contacts[index].setFirstName(input);
        break;
    }

    while (true)
    {
        std::cout << "Enter Last Name: ";
        if (std::getline(std::cin, input).eof())
            return;
        if (input.empty() || PhoneBook::emptyFieldCheck(input))
        {
            std::cout << "Last name cannot be empty. Please try again." << std::endl;
            continue;
        }
        contacts[index].setLastName(input);
        break;
    }

    while (true)
    {
        std::cout << "Enter Nick Name: ";
        if (std::getline(std::cin, input).eof())
            return;
        if (input.empty() || PhoneBook::emptyFieldCheck(input))
        {
            std::cout << "Nickname cannot be empty. Please try again." << std::endl;
            continue;
        }
        contacts[index].setNickName(input);
        break;
    }

    while (true)
    {
        std::cout << "Enter Phone Number: ";
        if (std::getline(std::cin, input).eof())
            return;
        if (input.empty() || PhoneBook::emptyFieldCheck(input))
        {
            std::cout << "Phone number cannot be empty. Please try again." << std::endl;
            continue;
        }
        contacts[index].setPhoneNumber(input);
        break;
    }

    while (true)
    {
        std::cout << "Enter Darkest Secret: ";
        if (std::getline(std::cin, input).eof())
            return;
        if (input.empty() || PhoneBook::emptyFieldCheck(input))
        {
            std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
            continue;
        }
        contacts[index].setDarkestSecret(input);
        break;
    }

    if (contactCount < 8)
        ++contactCount;

    std::cout << "Contact added successfully!" << std::endl;
}
void PhoneBook::displayContacts()
{
    if (contactCount == 0)
    {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << " |  Index   |First Name| Last Name| Nick Name|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << " |" << std::setw(10) << i << "|";
        std::string firstName = contacts[i].getFirstName();
        if (firstName.length() > 10)
        {
            firstName = firstName.substr(0, 9) + ".";
            std::cout << std::setw(10) << firstName << "|";
        }
        else
        {
            std::cout << std::setw(10) << firstName << "|";
        }
        std::string lastName = contacts[i].getLastName();
        if (lastName.length() > 10)
        {
            lastName = lastName.substr(0, 9) + ".";
            std::cout << std::setw(10) << lastName << "|";
        }
        else
        {
            std::cout << std::setw(10) << lastName << "|";
        }
        std::string nickName = contacts[i].getNickName();
        if (nickName.length() > 10)
        {
            nickName = nickName.substr(0, 9) + ".";
            std::cout << std::setw(10) << nickName << "|" << std::endl;
        }
        else
        {
            std::cout << std::setw(10) << nickName << "|" << std::endl;
        }
    }

    while (1)
    {
        int index;
        index = 0;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Enter the index of the contact to view details: ";
        std::string input;
        if (std::getline(std::cin, input).eof())
            return;
        if(!is_valid(input))
        {
            std::cout << "Invalid index. Please try again." << std::endl;
            continue;
        }
        index = std::atoi(input.c_str());
        if (index < 0 || index >= contactCount)
        {
            std::cout << "Invalid index. Please try again." << std::endl;
            continue;
        }
        else
        {
            std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
            std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
            std::cout << "Nick Name: " << contacts[index].getNickName() << std::endl;
            std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
            break;
        }
    }
}
