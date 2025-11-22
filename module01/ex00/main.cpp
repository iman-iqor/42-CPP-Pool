#include"Zombie.hpp"

int main()
{
    Zombie* z1 = newZombie("Foo");
    z1->announce();
    randomChump("stackZombie");
    delete z1;
    return 0;
}
