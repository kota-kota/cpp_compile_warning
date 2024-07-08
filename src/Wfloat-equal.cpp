/*
-Wfloat-equal
浮動小数点数が等しいかどうかをテストする場合に警告
*/
#include <cstdio>

namespace {
void equal(float f1, float f2) {
    if (f1 == f2) {
        printf("equal\n");
    } else {
        printf("not equal\n");
    }
}
}  // namespace

namespace my {
void Wfloat_equal() { equal(0.01f, 0.01f); }
}  // namespace my
