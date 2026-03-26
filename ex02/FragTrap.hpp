#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp" // 包含基类头文件
#include <iostream>

/**
 * FragTrap 类同样继承自 ClapTrap
 * 在 42 项目中，它通常代表着更高的攻击力和生命值，但能量回收略有不同
 */
class FragTrap : public ClapTrap
{
public:
    // --- 构造与析构函数 ---
    FragTrap();                                  // 默认构造函数
    FragTrap(std::string name);                  // 带参数的构造函数（初始化名字）
    FragTrap(const FragTrap &other);             // 拷贝构造函数
    ~FragTrap();                                 // 析构函数

    // --- 运算符重载 ---
    FragTrap &operator=(const FragTrap &other);  // 拷贝赋值运算符

    /**
     * @brief FragTrap 特有的功能
     * 向大家请求一个积极的高五反馈！
     */
    void highFivesGuys(void);

    /**
     * @brief 覆盖父类的攻击函数
     * 虽然 FragTrap 的 attack 逻辑可能与基类相似，
     * 但在实现时通常会打印具有 FragTrap 特色的文本。
     */
    void attack(const std::string &target);
};

#endif