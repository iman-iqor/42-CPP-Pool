#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    int i = 1;
    if (argc > 1)
    {
        while (argv[i])
        {

            int j = 0;
            while (argv[i][j])
            {
                if (isupper(argv[i][j]))
                {
                    std::cout << argv[i][j];
                }
                else if (islower(argv[i][j]))
                {
                    std::cout << (char)toupper(argv[i][j]) ;
                }
                else
                {
                    std::cout << argv[i][j];
                }
                j++;
            }
            i++;
        }
        std::cout<<"\n";
    }
    else
    {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }

}