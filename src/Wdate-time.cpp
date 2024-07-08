/*
-Wdate-time
__TIME__、__DATE__、__TIMESTAMP__ の使用について警告
*/
#include <cstdio>

namespace my {
void Wdate_time() { printf("%s %s %s\n", __TIME__, __DATE__, __TIMESTAMP__); }
}  // namespace my
