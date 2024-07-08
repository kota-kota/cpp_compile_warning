/*
-Wcast-align=strict
配置を増やすポインター キャストについて警告
=strictを付けないと警告されない
*/
#include <stdio.h>

void Wcast_align() {
    char* c = "cast_align";
    int* i = (int*)(c);
    printf("%d\n", *i);
}
