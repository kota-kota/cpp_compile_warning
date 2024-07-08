/*
-Wformat-nonliteral
リテラルではないフォーマット文字列について警告
*/
#include <cstdio>
#include <string>

namespace my {
void Wformat_nonliteral() {
    int i = 10;
    printf("number_i: %d\n", i);

    int j = 20;
    std::string format("number_j: %d\n");
    printf(format.c_str(), j);
}
}  // namespace my
