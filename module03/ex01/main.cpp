#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("a");
    ClapTrap b("b");

    a.beRepaired(10);
    b.beRepaired(10);

    a.attack("b");
    b.attack("a");

    a.guardGate();
    return 0;
}
