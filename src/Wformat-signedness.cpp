/*
-Wformat-signedness
フォーマット関数との符号の違いについて警告
[-Wformat=]として出力される
*/
#include <cstdio>
#include <string>

namespace my {
void Wformat_signedness() {
    std::uint32_t ui = 10U;
    printf("number_ui: %d\n", ui); /* フォーマット文字列の指定は符号有り、フォーマット引数は符号無し */

    std::int32_t i = 10;
    printf("number_i: %u\n", i); /* フォーマット文字列の指定は符号無し、フォーマット引数は符号有り */
}
}  // namespace my
