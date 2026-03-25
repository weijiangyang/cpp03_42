#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap Test ===" << std::endl;
    ClapTrap c1("CT-One");
    c1.attack("Target-A");
    c1.takeDamage(5);
    c1.beRepaired(3);

    std::cout << "\n=== ScavTrap Test ===" << std::endl;
    ScavTrap s1("ST-One");
    s1.attack("Target-B");
    s1.takeDamage(20);
    s1.beRepaired(10);
    s1.guardGate();

    std::cout << "\n=== FragTrap Test ===" << std::endl;
    FragTrap f1("FT-One");
    f1.attack("Target-C");
    f1.takeDamage(30);
    f1.beRepaired(15);
    f1.highFivesGuys();

    std::cout << "\n=== DiamondTrap Test ===" << std::endl;
    DiamondTrap d1("DT-One");
    d1.attack("Target-D");       // DiamondTrap attack
    d1.takeDamage(40);
    d1.beRepaired(20);
    d1.guardGate();              // from ScavTrap
    d1.highFivesGuys();          // from FragTrap
    d1.whoAmI();                 // DiamondTrap special

    std::cout << "\n=== Copy & Assignment Test ===" << std::endl;
    DiamondTrap d2(d1);          // copy constructor
    d2.whoAmI();
    
    DiamondTrap d3;
    d3 = d1;                     // assignment operator
    d3.whoAmI();

    std::cout << "\n=== End of Main ===" << std::endl;
    return 0;
}


