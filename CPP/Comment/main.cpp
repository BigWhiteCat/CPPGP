#include <iostream>

/*!
 * \brief 简单主函数.
 *        读取两个数，求它们的和
 * \return 返回0给操作系统，表示程序正确的结束
 */
int main() {
    std::cout << "Enter two numbers: " << std::endl;

    /*! v1 */
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;

    return 0;
}
