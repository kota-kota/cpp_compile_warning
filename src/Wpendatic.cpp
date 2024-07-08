/*
-Wpendatic
ISO C/C++標準に準拠しない実装に対して警告
*/
#include <cstdio>

namespace {
void func(int i) { printf("%d\n", i); };
};  // namespace

namespace my {
void Wpendatic() { func(100); }
}  // namespace my
