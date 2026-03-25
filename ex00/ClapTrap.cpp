#include <iostream>
#include "ClapTrap.hpp"

/**
 * 默认构造函数
 * 初始化各项数值为题目要求的默认值：10 HP, 10 EP, 0 AD
 */
ClapTrap::ClapTrap()
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " default constructor called" << std::endl;
}

/**
 * 带有名字参数的构造函数
 */
ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

/**
 * 拷贝构造函数
 * 使用 another 对象的数据来初始化新创建的对象
 */
ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), 
      _hitPoints(other._hitPoints), 
      _energyPoints(other._energyPoints), 
      _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " copy constructor called" << std::endl;
}

/**
 * 析构函数
 * 在对象生命周期结束时打印信息，方便观察对象销毁顺序
 */
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

/**
 * 拷贝赋值运算符重载
 * 将一个已有对象的值赋给另一个已存在的对象
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // 防止自我赋值 (a = a)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this; // 返回当前对象的引用，支持链式赋值 (a = b = c)
}

/**
 * 攻击动作
 * 逻辑：需要 HP > 0 且 EP > 0 才能发动。发动后 EP 减 1。
 */
void ClapTrap::attack(const std::string &target)
{
    // 检查状态：没血或没能量都不能动
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack (low HP or Energy)" << std::endl;
        return;
    }
    _energyPoints--; // 消耗能量
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

/**
 * 承受伤害
 * 逻辑：血量减去伤害值，且血量不能低于 0
 */
void ClapTrap::takeDamage(unsigned int amount)
{
    // 计算实际受到的伤害值，防止血量溢出（unsigned 类型溢出会变极大值）
    unsigned int damageTaken = (amount >= _hitPoints) ? _hitPoints : amount;
    
    _hitPoints -= damageTaken;
    
    std::cout << "ClapTrap " << _name << " takes "
              << damageTaken << " points of damage! Remaining HP: " << _hitPoints << std::endl;
}

/**
 * 自我修复
 * 逻辑：需要 HP > 0 且 EP > 0 才能发动。发动后 HP 增加，EP 减 1。
 */
void ClapTrap::beRepaired(unsigned int amount)
{
    // 死亡或没能量无法修复
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't repair itself" << std::endl;
        return;
    }
    _hitPoints += amount; // 恢复生命
    _energyPoints--;      // 消耗能量
    std::cout << "ClapTrap " << _name << " repairs itself for "
              << amount << " HP! Total HP: " << _hitPoints << std::endl;
}