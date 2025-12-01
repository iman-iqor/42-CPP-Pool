#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("a");
    ClapTrap b("b");
    a.attack("b");
    b.takeDamage(0);
    b.beRepaired(5);
    b.attack("a");
    a.takeDamage(3);
    a.beRepaired(2);
    return 0;   
}
