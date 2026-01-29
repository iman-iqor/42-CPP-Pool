#include "ScalarConverter.hpp"
#include <sstream>
#include <climits>
#include <cctype>
#include <cstdlib>

static bool isPseudoLiteral(const std::string &s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff" ||
            s == "+nan" || s == "+nanf" ||
            s == "-nanf" || s == "-nanf");
}

static void handle_empty_input()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
static void handle_char_input(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
static void handle_pseudo_literal(const std::string &input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (input == "nan" || input == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input == "+inf" || input == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (input == "+nan" || input == "+nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input == "-nan" || input == "-nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

static bool isInteger(const std::string input)
{
    std::stringstream ss(input);
    long i;
    ss >> i;
    if (ss.fail() || !ss.eof())
    {
        std::cout << "bad input" << std::endl;
        return false;
    }
    else
        return true;
}

void ScalarConverter::convert(const std::string &input)
{
    if (input.empty())
    {
        handle_empty_input();
        return;
    }

    if (input.length() == 1 && !std::isdigit(input[0])) // char
    {
        char c = input[0];

        handle_char_input(c);
        return;
    }

    if (isPseudoLiteral(input))
    {
        handle_pseudo_literal(input);
        return;
    }

    if (isInteger(input))
    {
        std::stringstream ss(input);
        long long num;
        ss >> num;
        if (num >= INT_MAX || num <= INT_MIN)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << num<<".0f"<<std::endl;
            std::cout << "double:" << num<<".0"<<std::endl;
        }
        else
        {
            std::cout << "char: " <<static_cast<char>(num)<< std::endl;
            std::cout << "int: " << num<< std::endl;
            std::cout << "float: " << num<<".0f"<<std::endl;
            std::cout << "double:" << num<<".0"<<std::endl;
        }

        return;
    }
}
