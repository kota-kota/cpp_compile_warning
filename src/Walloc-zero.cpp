/*
-Walloc-zero
ゼロバイトを指定する割り当て関数の呼び出しに対して警告
*/
#include <cstdint>

namespace my {
void Walloc_zero() {
    constexpr std::size_t size = 0;
    char* p = new char[size];
    delete p;
}
}  // namespace my
