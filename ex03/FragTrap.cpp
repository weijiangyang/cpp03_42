#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("default")
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << _name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests a positive high five! ✋" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " can't attack" << std::endl;
		return;
	}

	energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage!" << std::endl;
}

