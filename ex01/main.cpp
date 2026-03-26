/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <weiyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:17:55 by weiyang           #+#    #+#             */
/*   Updated: 2026/03/26 13:17:56 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap test ===" << std::endl;
    ClapTrap clap1("CL4P-TP");
    clap1.attack("Target1");
    clap1.takeDamage(5);
    clap1.beRepaired(3);

    std::cout << "\n=== ScavTrap test ===" << std::endl;
    ScavTrap scav1("SC4V-TP");
    scav1.attack("Target2");
    scav1.takeDamage(20);
    scav1.beRepaired(10);
    scav1.guardGate();

    std::cout << "\n=== Copy & Assignment test ===" << std::endl;
    ScavTrap scav2(scav1);
    ScavTrap scav3;
    scav3 = scav1; 

    std::cout << "\n=== Destruction test ===" << std::endl;
    return 0;
}