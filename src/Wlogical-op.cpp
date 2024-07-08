/*
-Wlogical-op
論理演算子が常に true または false に評価されると疑わしい場合に警告

論理演算子の使用で誤りが疑われる場合警告を出力
*/
#include <cstdint>
#include <cstdio>

namespace my {
void Wlogical_op() {
    int v = 10;
    if (v && 2) {
        printf("NG\n");
    }
}
}  // namespace my
