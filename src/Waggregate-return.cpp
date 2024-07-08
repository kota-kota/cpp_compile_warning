/*
-Waggregate-return
構造体や共用体を返す関数の定義・呼び出しがある場合に警告
*/

namespace {
struct Hoge {
    int v1_;
    int v2_;
};
Hoge func() { /* 警告: 構造体を返す関数の呼び出し */
    Hoge hoge;
    hoge.v1_ = 0;
    hoge.v2_ = 0;
    return hoge;
}
}  // namespace

namespace my {
void Waggregate_return() { (void)func(); }
}  // namespace my
