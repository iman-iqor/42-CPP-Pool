#include "BitcoinExchange.hpp"

int is_valid_file(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file" << std::endl;
        return 0;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return 0;
    }
    std::string line;
    if (!std::getline(file, line))
    {
        std::cout << "Error: empty file" << std::endl;
        return 0;
    }
    return 1;
}

bool isValidDate(std::string &date)
{
    
    if (date.size() != 10)
    {
        std::cout<<"size"<<std::endl;
        return false; 
    }

    
    if (date[4] != '-' || date[7] != '-')
    {
        std::cout<<"tiri"<<std::endl;
        return false;
    }

    
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue; 
        if (!std::isdigit(date[i]))
        {
            std::cout<<"not digit"<<std::endl;
            return false;
        }
    }

    return true;
}
bool isValidAmount(std::string &amount)
{
    std::stringstream ss(amount);
    float valNum;
    ss >> valNum;
    if (ss.fail() || !ss.eof())
        return false;
    if(valNum < 0 || valNum > 1000)
        return false;
    return true;
}
std::string delete_spaces(std::string s)
{
    std::string newStr;
    for(unsigned int i = 0;i < s.size();i++)
    {
        if(s[i] != ' ')
            newStr += s[i];
    }
    return newStr;
}
int main(int argc, char **argv)
{
    if (!is_valid_file(argc, argv))
    {
        return 1;
    }
    std::ifstream file(argv[1]);
    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cout << "there is no |" << std::endl;
        }
        else
        {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos+1);

            std::cout << "key:" << key << std::endl;
            std::cout << "value:" << value << std::endl;
            std::string newKey = delete_spaces(key);
            std::string newValue = delete_spaces(value);
             std::cout << "key:" << newKey << std::endl;
            std::cout << "value:" << newValue << std::endl;
            // parse the key
            if (!isValidDate(newKey))
                std::cout << "the date is not valid" << std::endl;
            // parse the value
            if(!isValidAmount(newValue))
                std::cout<<"the amount is not valid"<<std::endl;
        }
    }

    return 0;
}