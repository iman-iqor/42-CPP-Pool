#include "ScalarConverter.hpp"
#include <sstream>
#include <climits>
#include <cctype>
#include <cstdlib>

static bool isPseudoLiteral(const std::string &s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff");
}

void ScalarConverter::convert(const std::string &input)
{
    if (input.empty())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    /* ===================== CHAR ===================== */
    if (input.length() == 1 && !std::isdigit(input[0]))
    {
        char c = input[0];

        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    /* ===================== PSEUDO LITERALS ===================== */
    if (isPseudoLiteral(input))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (input == "nan" || input == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (input[0] == '+')
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return;
    }

    /* ===================== FLOAT / DOUBLE ===================== */
    bool isFloat = false;
    std::string number = input;

    if (input[input.length() - 1] == 'f')
    {
        isFloat = true;
        number = input.substr(0, input.length() - 1);
    }

    if (number.find('.') != -1)//find returns -1 if not found
    {
        std::stringstream ss(number);
        double d;
        ss >> d;

        if (ss.fail() || !ss.eof())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }

        /* char */
        if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        /* int */
        if (d >= INT_MIN && d <= INT_MAX)
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;

        /* float */
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

        /* double */
        std::cout << "double: " << d << std::endl;

        return;
    }

    /* ===================== INT ===================== */
    std::stringstream ss(input);
    int i;
    ss >> i;

    if (ss.fail() || !ss.eof())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    /* char */
    if (i >= 0 && i <= 127 && std::isprint(i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    /* int */
    std::cout << "int: " << i << std::endl;

    /* float */
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;

    /* double */
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}
