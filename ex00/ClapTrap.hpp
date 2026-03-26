/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <weiyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:05:25 by weiyang           #+#    #+#             */
/*   Updated: 2026/03/26 13:05:26 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
class ClapTrap
{
	private:
		std::string  _name;          
		unsigned int _hitPoints;   
		unsigned int _energyPoints; 
		unsigned int _attackDamage;

	public: 
		ClapTrap();                            
		ClapTrap(std::string name);                 
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);          
		~ClapTrap();                                
		
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
