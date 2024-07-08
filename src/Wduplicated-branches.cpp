/*
-Wduplicated-branches
if-else ステートメント内の重複した分岐について警告
*/
#include <cstdio>

namespace my {
void Wduplicated_branches() {
    for (int i = 0; i < 2; i++) {
        /* if else ともに同じ内容の処理 */
        if (i == 0) {
            printf("%d\n", i);
        } else {
            printf("%d\n", i);
        }
    }
}
}  // namespace my
