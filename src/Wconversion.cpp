/*
-Wconversion
値を変更する可能性のある暗黙的な型変換について警告
*/
namespace {
void func(char c, int i) { c = c + i; /* -Wconversionで警告 */ }
}  // namespace

namespace my {
void Wconversion() { func('A', 1); }
}  // namespace my
