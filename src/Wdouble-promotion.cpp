/*
-Wdouble-promotion
「float」から「double」への暗黙的な変換について警告
*/
#include <cstdio>

namespace my {
void Wdouble_promotion() {
    float f1 = 0.1; /* -Wdouble-promotionでは警告出ないが、-Wfloat-conversionでは警告出る */
    float f2 = f1 * 0.25;
    printf("%f\n", static_cast<double>(f2));
}
}  // namespace my
