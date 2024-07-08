/*
-Wformat-y2k
2 桁の年を生成する strftime 形式について警告
*/
#include <cstdio>
#include <ctime>

namespace my {
void Wformat_y2k() {
    time_t tt;
    std::time(&tt);
    struct tm *tptr = localtime(&tt);

    /* %y : 年(2桁)を出力 */
    char c[10];
    size_t n = strftime(c, sizeof(c) - 1, "%y", tptr);

    printf("[%s] : %ld\n", c, n);
}
}  // namespace my
