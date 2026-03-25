/*这份代码展示了 C++ 中经典的 **Canonical Form（标准形式）** 类定义。针对你提供的 `ClapTrap.hpp` 头文件，我为你添加了详细的中文注释，解释了每个成员变量和成员函数的作用。
*/
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

// ClapTrap 类定义
class ClapTrap
{
private:
    // 私有属性：仅类内部可以访问
    std::string  _name;          // ClapTrap 的名字
    unsigned int _hitPoints;     // 生命值 (HP)
    unsigned int _energyPoints;  // 能量点 (用于攻击和修复)
    unsigned int _attackDamage;  // 攻击力

public:
    // --- 构造函数与析构函数 ---
    
    ClapTrap();                                  // 默认构造函数
    ClapTrap(std::string name);                 // 带参数的构造函数（初始化名字）
    ClapTrap(const ClapTrap &other);            // 拷贝构造函数（用于深拷贝）
    ~ClapTrap();                                 // 析构函数（对象销毁时调用）

    // --- 运算符重载 ---
    
    ClapTrap &operator=(const ClapTrap &other); // 拷贝赋值运算符重载

    // --- 成员函数 (行为) ---

    /**
     * 攻击目标
     * 消耗 1 能量点。如果能量或生命值为 0，则无法行动。
     */
    void attack(const std::string &target);

    /**
     * 承受伤害
     * 根据 amount 扣除生命值。
     */
    void takeDamage(unsigned int amount);

    /**
     * 修复/回血
     * 消耗 1 能量点，恢复 amount 生命值。
     */
    void beRepaired(unsigned int amount);
};

#endif
/*
---

### 关键点说明：

*   **Header Guard (`#ifndef`)**: 防止头文件被重复包含导致的编译错误。
*   **Canonical Form**: 在 42 校园或类似的 C++ 规范中，一个完整的类通常需要包含：**默认构造、拷贝构造、拷贝赋值运算符、析构函数**。
*   **属性逻辑**:
    *   **攻击 (attack)** 和 **修复 (beRepaired)** 通常需要检查 `hitPoints > 0` 且 `energyPoints > 0`。
    *   **受到伤害 (takeDamage)** 只需要更新 `hitPoints`，通常不需要消耗能量。

*/
