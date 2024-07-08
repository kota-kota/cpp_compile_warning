/*
-Wformat-security
フォーマット関数で発生する可能性のあるセキュリティ上の問題について警告
*/
#include <cstdio>
#include <string>

namespace my {
void Wformat_security() {
    int i = 10;
    std::string format("number_i: %d\n");
    printf(format.c_str(), i); /* -Wformat-nonliteralで警告が出る */
    printf(format.c_str());    /* -Wformat-securityで警告が出る */
}
}  // namespace my
