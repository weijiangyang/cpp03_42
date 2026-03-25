#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap test ===" << std::endl;
    ClapTrap clap("CL4P-TP");
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n=== ScavTrap test ===" << std::endl;
    ScavTrap scav("SC4V-TP");
    scav.attack("Target2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n=== FragTrap test ===" << std::endl;
    FragTrap frag("FR4G-TP");
    frag.attack("Enemy1");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n=== Copy & Assignment test ===" << std::endl;
    FragTrap frag2(frag); // 拷贝构造
    FragTrap frag3;
    frag3 = frag;          // 赋值操作符

    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}


