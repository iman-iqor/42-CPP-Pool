#include "FragTrap.hpp"

int main()
{
    FragTrap a("a");
    ClapTrap b("b");

    a.beRepaired(10);
    b.beRepaired(10);

    a.attack("b");
    b.attack("a");

    a.highFivesGuys();
    return 0;
}
