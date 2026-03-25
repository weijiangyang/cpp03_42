#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "default";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << _name << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other) // 调用父类的拷贝构造
{
	std::cout << "ScavTrap " << _name << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack" << std::endl;
		return;
	}

	energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}