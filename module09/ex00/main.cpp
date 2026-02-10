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
        std::cout << "size" << std::endl;
        return false;
    }

    if (date[4] != '-' || date[7] != '-')
    {
        std::cout << "tiri" << std::endl;
        return false;
    }

    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
        {
            std::cout << "not digit" << std::endl;
            return false;
        }
    }
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    std::stringstream ssYear(yearStr);
    std::stringstream ssMonth(monthStr);
    std::stringstream ssDay(dayStr);
    int year, month, day;
    ssYear >> year;
    ssMonth >> month;
    ssDay >> day;
    if (ssYear.fail() || ssMonth.fail() || ssDay.fail())
    {
        std::cout << "conversion failed" << date << std::endl;
        return false;
    }
    if (year < 2009 || year > 2023)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    if (month < 1 || month > 12)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    if (day < 1 || day > 31)
    {
        std::cout << "Error: bad input => " << date << std::endl;
    }

    return true;
}
bool isValidAmount(std::string &amount)
{
    std::stringstream ss(amount);
    double valNum;
    ss >> valNum;
    if (ss.fail() || !ss.eof())
        return false;

    if (valNum < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (valNum > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}
std::string delete_spaces(std::string s)
{
    std::string newStr;
    for (unsigned int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
            newStr += s[i];
    }
    return newStr;
}

std::map<std::string, double> refDataMap(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    std::string line;
    std::map<std::string, double> data;
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
        {
            std::cout << "there is no ," << std::endl;
        }
        else
        {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            std::string newKey = delete_spaces(key);
            std::string newValue = delete_spaces(value);

            if (newKey == "date" && newValue == "exchange_rate")
                continue;

            // store the valid line in the map
            else
            {
                std::stringstream ss(newValue);
                double val;
                ss >> val;
                std::map<std::string, double>::iterator it = data.find(newKey);
                if (it != data.end())
                {
                    std::cout << "the " << newKey << "would be updated" << std::endl;
                }
                else
                    data[newKey] = val;
            }
        }
    }
    return data;
}

int main(int argc, char **argv)
{
    if (!is_valid_file(argc, argv))
    {
        return 1;
    }

    std::ifstream reffile("data.csv");
    if (!reffile.is_open())
    {
        std::cout << "Error: could not open csv file" << std::endl;
        return 0;
    }

    std::map<std::string, double> refMap = refDataMap("data.csv");

    std::ifstream file(argv[1]);
    std::string line;
    std::map<std::string, double> data;
    while (std::getline(file, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
        }
        else
        {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            std::string newKey = delete_spaces(key);
            std::string newValue = delete_spaces(value);
            // std::cout << "newKey: " << newKey << ", newValue: " << newValue << std::endl;

            if ((newKey == "date" && newValue == "value") || (newKey == "Date" && newValue == "Value"))
                continue;

            // parse the key and the value
            if (!isValidDate(newKey) || !isValidAmount(newValue))
            {

                continue;
            }

            std::map<std::string, double>::iterator it = refMap.lower_bound(newKey);
            if (it != refMap.end() && it->first == newKey)
            {
                std::stringstream ss(newValue);
                double val;
                ss >> val;
                std::cout << newKey << " => " << newValue << " = " << (val * it->second) << std::endl;
            }
            else
            {
                if (it == refMap.begin())
                {
                    std::cout << "there is no earlier date!" << std::endl;
                    continue;
                }
                if (it == refMap.end())
                {

                    it--;
                }
                else
                {
                    it--;
                }
                std::stringstream ss(newValue);
                double val;
                ss >> val;
                std::cout << newKey << " => " << newValue << " = " << (val * it->second) << std::endl;
            }
        }
    }

    return 0;
}
