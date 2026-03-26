/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <weiyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:43:24 by weiyang           #+#    #+#             */
/*   Updated: 2026/03/26 13:43:25 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    d1.attack("Target-D");       
    d1.takeDamage(40);
    d1.beRepaired(20);
    d1.guardGate();              
    d1.highFivesGuys();       
    d1.whoAmI();                

    std::cout << "\n=== Copy & Assignment Test ===" << std::endl;
    DiamondTrap d2(d1);        
    d2.whoAmI();
    
    DiamondTrap d3;
    d3 = d1;                 
    d3.whoAmI();

    std::cout << "\n=== End of Main ===" << std::endl;
    return 0;
}


