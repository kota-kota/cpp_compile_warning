/*
-Wcast-align=strict
配置を増やすポインター キャストについて警告
=strictを付けないと警告されない
*/
#include <cstdio>

namespace my {
void Wcast_align() {
    char c[] = "cast_align";
    int* i = reinterpret_cast<int*>(c);
    printf("%d\n", *i);
}
}  // namespace my
