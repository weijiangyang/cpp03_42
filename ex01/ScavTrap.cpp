#include "ScavTrap.hpp"

// --- 默认构造函数 ---
// 显式调用父类 ClapTrap() 构造函数
ScavTrap::ScavTrap() : ClapTrap()
{
    // 修改继承自父类的属性，以符合 ScavTrap 的高性能设定
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " default constructor called" << std::endl;
}

// --- 有参构造函数 ---
// 将 name 传递给父类构造函数进行初始化
ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

// --- 拷贝构造函数 ---
// 通过 : ClapTrap(other) 实现“切片式拷贝”：
// 自动将 other 对象中属于父类的部分拷贝到当前对象的父类空间中
ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other) 
{
    std::cout << "ScavTrap " << _name << " copy constructor called" << std::endl;
}

// --- 析构函数 ---
// 执行顺序：先执行子类析构逻辑，再自动调用父类析构函数
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

// --- 拷贝赋值运算符 ---
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other) // 自赋值检查
    {
        // 关键：显式调用父类的赋值运算符来更新父类成员变量
        ClapTrap::operator=(other);
    }
    return (*this);
}

// --- 攻击动作 (函数覆盖) ---
void ScavTrap::attack(const std::string &target)
{
    // 逻辑判定：ScavTrap 虽然更强，但也受限于生命值和能量
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack (Low HP/Energy)" << std::endl;
        return;
    }

    _energyPoints--; // 消耗 1 点能量
    std::cout << "ScavTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// --- 特有技能：守门员模式 ---
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}