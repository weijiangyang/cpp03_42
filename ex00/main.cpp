#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Robot");

    a.attack("enemy");
    a.takeDamage(3);
    a.beRepaired(5);
}