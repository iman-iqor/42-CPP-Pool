

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        std::string fileName = argv[1];
        std::ifstream infile(fileName.c_str());
        if (!infile.is_open())
        {
            std::cerr << "Error: cannot open file '" << fileName << "'" << std::endl;
            return 1;
        }
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        if (s1.empty() || s2.empty())
        {
            std::cerr << "Error: strings s1 and s2 must not be empty" << std::endl;
            return 1;
        }
        std::string content;
        std::string line;
        while (std::getline(infile, line))
        {
            content += line;
            if (!infile.eof())
                content += "\n";
        }

        std::string result;
        std::string::size_type pos = 0;
        while (true)
        {
            std::string::size_type found = content.find(s1, pos);
            if (found == std::string::npos)
            {
                result += content.substr(pos);
                break;
            }
            result += content.substr(pos, found - pos);
            result += s2;
            pos = found + s1.length();
        }

        std::ofstream outfile((fileName + ".replace").c_str());
        if (!outfile.is_open())
        {
            std::cerr << "Error: cannot create output file '" << fileName + ".replace" << "'" << std::endl;
            return 1;
        }
        outfile << result;
    }
    else
    {
        std::cout << "Usage: " << argv[0] << " a filename and two strings, s1 and s2" << std::endl;
    }
    return 0;
}