#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp" // 必须包含父类的头文件

/**
 * ScavTrap 类继承自 ClapTrap
 * 继承方式为 public，意味着父类的 public/protected 成员在子类中保持原有属性
 */
class ScavTrap : public ClapTrap
{
    public:
        // --- 构造与析构函数 ---
        ScavTrap();                                  // 默认构造函数
        ScavTrap(std::string name);                  // 带参数的构造函数
        ScavTrap(const ScavTrap &other);             // 拷贝构造函数
        ~ScavTrap();                                 // 析构函数

        // --- 运算符重载 ---
        ScavTrap &operator=(const ScavTrap &other);  // 拷贝赋值运算符

        /**
         * @brief 覆盖 (Override) 父类的攻击函数
         * ScavTrap 的攻击描述通常与 ClapTrap 不同，展现其更强的一面
         */
        void attack(const std::string &target);

        /**
         * @brief ScavTrap 的特殊能力
         * 开启 "守门员" 模式，打印一条进入该模式的消息
         */
        void guardGate();
};

#endif