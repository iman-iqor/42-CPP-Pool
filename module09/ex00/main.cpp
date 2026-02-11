#include "BitcoinExchange.hpp"



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
