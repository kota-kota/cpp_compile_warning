/*
-Wcast-qual
修飾子を破棄するキャストについて警告
*/
#include <cstdio>

namespace {
void func(const int* const i) {
    int* v = (int*)i;
    *v = 20;
}
}  // namespace

namespace my {
void Wcast_qual() {
    int i = 10;
    func(&i);
    printf("%d\n", i);
}
}  // namespace my
