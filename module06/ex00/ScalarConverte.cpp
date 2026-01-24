#include"ScalarConverte.hpp"


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

}