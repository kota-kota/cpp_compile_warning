/*
-Wduplicated-cond
if-else-if チェーン内の重複した条件について警告
*/
#include <cstdio>

namespace my {
void Wduplicated_cond() {
    for (int i = 0; i < 2; i++) {
        /* if else-if ともに同じ条件 */
        if (i == 0) {
            printf("%d\n", i);
        } else if (i == 0) {
            printf("%d\n", i);
        } else {
            printf("%d\n", i);
        }
    }
}
}  // namespace my
