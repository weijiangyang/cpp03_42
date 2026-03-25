#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), 
      hitPoints(other.hitPoints), 
      energyPoints(other.energyPoints), 
      attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << _name << " copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int damageTaken = (amount >= hitPoints) ? hitPoints : amount;
	hitPoints = (amount >= hitPoints) ? 0 : hitPoints - amount;
	std::cout << "ClapTrap " << _name << " takes "
			  << damageTaken << " points of damage!" << std::endl;
}

void ClapTrap ::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair itself" << std::endl;
		return;
	}
	hitPoints += amount;
	energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself for "
			  << amount << " HP" << std::endl;
}
