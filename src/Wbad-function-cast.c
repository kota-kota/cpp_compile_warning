/*
-Wbad_function_cast
互換性のない型への関数のキャストについて警告
C/Object-Cのみ
*/

#include <stdbool.h>
#include <stdio.h>

bool func() { return false; }

void Wbad_function_cast() {
    int v = (int)func();
    printf("%d\n", v);
}
