/*
-Winline
インライン化された関数をインライン化できない場合に警告

インライン展開されない関数を作るのは面倒なので一旦保留。
*/
#include <cstdio>

namespace {
inline int add(int v1, int v2) { return v1 + v2; }
inline void hoge() { printf("hoge\n"); }
}  // namespace

namespace my {
void Winline() {
    printf("add: %d\n", add(1, 2));
    hoge();
}
}  // namespace my
