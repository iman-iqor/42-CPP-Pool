#include"ScalarConverter.hpp"


static bool isPseudoLiteral(const std::string& s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff");
}

void ScalarConverte::convert(std::string &input)
{
    if(input.empty())
    {
        std::cout << "Empty input provided." << std::endl;
        return;
    }
    else if(!isprint(input[0]))
    {
        std::cout << "Non displayable." << std::endl;
    }
    else if(input.length() == 1 && !isdigit(input[0]))
    {
        // Handle single character input
        char c = static_cast<char>(input[0]);
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        
    }
    if (isPseudoLiteral(input))
    {
        // char
        std::cout << "char: impossible" << std::endl;

        // int
        std::cout << "int: impossible" << std::endl;

        // float
        if (input == "nan" || input == "nanf")
            std::cout << "float: nanf" << std::endl;
        else if (input == "+inf" || input == "+inff")
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;

        // double
        if (input == "nan" || input == "nanf")
            std::cout << "double: nan" << std::endl;
        else if (input == "+inf" || input == "+inff")
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;

        return;
    }

}