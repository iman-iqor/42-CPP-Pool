#include "RPN.hpp"

bool isOperation(char symbole)
{
    if (symbole == '+' || symbole == '-' || symbole == '*' || symbole == '/')
        return true;
    return false;
}
void doOperation(char symbole, std::stack<int> &s)
{
    int b = static_cast<int> (s.top());
    s.pop();
    int a = static_cast<int> (s.top());
    s.pop();
    int tmp = 0;
    if (symbole == '+')
    {   
        tmp = a + b;
        s.push(tmp);
    }
    else if (symbole == '-')
    {

        tmp = a - b;
        s.push(tmp);
    }
    else if (symbole == '*')
    {

        tmp = a * b;
        s.push(tmp);
    }
    else if (symbole == '/')
    {
        tmp = a / b;
        s.push(tmp);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    // try

    if (!argv || !argv[0])
    {
        std::cout << "empty argument" << std::endl;
        return 1;
    }
    int i = 0;
    std::stack<int> s;
    while (argv[1][i])
    {
        if (isdigit(argv[1][i]))
        {
            s.push(argv[1][i] - '0');
        }
        else if (isOperation(argv[1][i]) && s.size()>=2)
        {
            
            doOperation(argv[1][i],s);
        }
        else if ((argv[1][i])==' ')
        {
            i++;
            continue;
        }
        else
        {
            std::cout<<"eror"<<std::endl;
            return 1;
        }
        
        i++;
    }
    if(s.size() != 1)
    {
        std::cout<<"error"<<std::endl;
        return 1;
    }
    std::cout<<static_cast<int>(s.top())<<std::endl;

    return 0;
}