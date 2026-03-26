#ifndef CLAPTRAP_HPP  // 防止头文件被重复包含的宏保护 (Include Guard)
#define CLAPTRAP_HPP

#include <string>     // 引入字符串库
#include <iostream>   // 通常建议加上，用于在实现文件中输出动作

class ClapTrap
{
    protected: // 受保护权限：子类可以访问，外部不可访问（实现继承的关键）
        std::string     _name;         // ClapTrap 的名称
        unsigned int    _hitPoints;     // 生命值 (HP)
        unsigned int    _energyPoints;  // 能量值（执行动作需要消耗）
        unsigned int    _attackDamage;  // 攻击力

    public:
        // --- 构造与析构函数 (遵循 C++ Standard Form) ---
        ClapTrap();                                  // 默认构造函数
        ClapTrap(std::string name);                  // 带参数的构造函数
        ClapTrap(const ClapTrap &other);             // 拷贝构造函数 (Copy Constructor)
        ~ClapTrap();                                 // 析构函数 (Destructor)

        // --- 运算符重载 ---
        ClapTrap &operator=(const ClapTrap &other);  // 拷贝赋值运算符重载 (Copy Assignment Operator)

        // --- 动作成员函数 ---
        /**
         * @brief 攻击目标
         * 消耗 1 点能量，造成 attackDamage 伤害
         */
        void attack(const std::string &target);

        /**
         * @brief 受到伤害
         * 降低 hitPoints，不能低于 0
         */
        void takeDamage(unsigned int amount);

        /**
         * @brief 修复/回血
         * 消耗 1 点能量，增加 hitPoints
         */
        void beRepaired(unsigned int amount);
};

#endif