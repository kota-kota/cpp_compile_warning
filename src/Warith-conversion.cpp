/*
-Warith-conversion
オペランドの変換では変更できない場合でも、算術結果の変換によって値が変更される可能性がある場合に警告
-Wconversionが有効の場合にのみ有効になる

-Wconversion
値を変更する可能性のある暗黙的な型変換について警告
*/
namespace {
void func(char c) { c = c + 1; /* -WWarith-conversionで警告 */ }
}  // namespace

namespace my {
void Warith_conversion() { func('A'); }
}  // namespace my
