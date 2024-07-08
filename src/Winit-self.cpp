/*
-Winit-self
変数自身により初期化されている変数がある場合に警告
-Wuninitializedで警告されるため、あまり意味がない？
*/
#include <cstdio>

namespace my {
void Winit_self() {
    // int i = i; /* -Winit-selfではなく、-Wuninitializedの警告が出る */
    int i = 10;
    printf("number_i: %d\n", i);
}
}  // namespace my
