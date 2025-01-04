#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// 静态存储期
// 满足以下所有条件的变量具有静态存储期：

// 它属于命名空间作用域，或者首先声明有 static 或 extern。
// 它不具有线程存储期。
// (C++11 起)
// 这些实体的存储在程序运行期间持续存在。
// THINK: 这个函数的两个 `static` 各自的作用是什么？
static int func(int param) {
    static int static_ = param;
    // std::cout << "static_ = " << static_ << std::endl;
    return static_++;
}

int main(int argc, char **argv) {
    // 将下列 `?` 替换为正确的数字
    // 首次调用func时，static_被初始化为5
    ASSERT(func(5) == 5, "static variable value incorrect");
    // 第二次调用func时，static_的值为6
    ASSERT(func(4) == 6, "static variable value incorrect");
    // 第三次调用func时，static_的值为7
    ASSERT(func(3) == 7, "static variable value incorrect");
    // 第四次调用func时，static_的值为8
    ASSERT(func(2) == 8, "static variable value incorrect");
    // 第五次调用func时，static_的值为9
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}
