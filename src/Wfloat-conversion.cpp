/*
-Wfloat-conversion
浮動小数点精度の損失を引き起こす暗黙的な型変換について警告
*/
#include <cstdio>

namespace my {
void Wfloat_conversion() {
    float f1 = 0.1; /* -Wdouble-promotionでは警告出ないが、-Wfloat-conversionでは警告出る */
    printf("%f\n", static_cast<double>(f1));
}
}  // namespace my
