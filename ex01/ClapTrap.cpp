#include <iostream>
#include "ClapTrap.hpp"

// --- 默认构造函数 ---
// 使用初始化列表将属性设为默认值 (10 HP, 10 EP, 0 AD)
ClapTrap::ClapTrap()
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " default constructor called" << std::endl;
}

// --- 有参构造函数 ---
ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

// --- 拷贝构造函数 ---
// 用于通过现有对象创建一个完全相同的新对象
ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), 
      _hitPoints(other._hitPoints), 
      _energyPoints(other._energyPoints), 
      _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " copy constructor called" << std::endl;
}

// --- 析构函数 ---
// 对象生命周期结束时自动调用
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

// --- 拷贝赋值运算符重载 ---
// 用于将一个已存在的对象赋值给另一个已存在的对象
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // 自赋值检查：防止 a = a 的情况导致错误
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this; // 返回自身引用以支持链式赋值 (a = b = c)
}

// --- 攻击动作 ---
void ClapTrap::attack(const std::string &target)
{
    // 逻辑判定：如果没有生命值或能量，无法行动
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack (No HP or Energy)" << std::endl;
        return;
    }
    _energyPoints--; // 攻击消耗 1 点能量
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// --- 受到伤害 ---
void ClapTrap::takeDamage(unsigned int amount)
{
    // 这里的逻辑处理了溢出：如果伤害大于剩余血量，血量归零，不设为负数
    unsigned int damageTaken = (amount >= _hitPoints) ? _hitPoints : amount;
    _hitPoints = (amount >= _hitPoints) ? 0 : _hitPoints - amount;
    
    std::cout << "ClapTrap " << _name << " takes "
              << damageTaken << " points of damage! Remaining HP: " << _hitPoints << std::endl;
}

// --- 自我修复 ---
void ClapTrap::beRepaired(unsigned int amount)
{
    // 逻辑判定：死亡或没蓝不能回血
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't repair itself" << std::endl;
        return;
    }
    _hitPoints += amount; // 增加血量
    _energyPoints--;      // 修复消耗 1 点能量
    std::cout << "ClapTrap " << _name << " repairs itself for "
              << amount << " HP! Total HP: " << _hitPoints << std::endl;
}
