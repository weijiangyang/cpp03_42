#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/**
 * DiamondTrap：这种机器人是 ScavTrap 和 FragTrap 的混合体
 * 
 * 挑战点：
 * 1. 它拥有自己的 _name 属性，同时继承了 ClapTrap 的 _name。
 * 2. 它的属性值混合自两个父类：
 *    - HP: 来自 FragTrap (100)
 *    - Energy: 来自 ScavTrap (50)
 *    - Damage: 来自 FragTrap (30)
 * 3. 它的 attack() 动作必须是 ScavTrap 的版本。
 */
class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name; // DiamondTrap 专属的私有名称

    public:
        // --- 构造与析构 ---
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &other);
        ~DiamondTrap();

        // --- 运算符重载 ---
        DiamondTrap &operator=(const DiamondTrap &other);

        /**
         * @brief 显式使用 ScavTrap 的攻击函数
         */
        void attack(const std::string &target);

        /**
         * @brief DiamondTrap 特有技能
         * 打印自己的名字以及继承自 ClapTrap 的名字
         */
        void whoAmI();
};

#endif
