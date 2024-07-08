/*
-Walloca
alloca の使用について警告
*/
#include <cstdio>
#include <cstdlib>

namespace my {
void Walloca() {
    constexpr std::size_t size = 0;
    void* p = alloca(size);
    (void)printf("%p\n", p);
}
}  // namespace my
