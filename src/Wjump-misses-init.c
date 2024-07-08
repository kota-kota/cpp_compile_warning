/*
-Wjump-misses-init
ジャンプで変数の初期化が失敗した場合に警告
*/
#include <stdio.h>

void func_goto() {
    int i = 10;
    goto end;

    {
        /* ここはOK */
        int j = 10;
        printf("number_j: %d\n", j);
    }

    int j = 10; /* ここで警告が出る */
    printf("number_j: %d\n", j);

end:
    printf("number_i: %d\n", i);
}

#if 0  // -Wjump-misses-initが無くてもビルドエラーになるため無効
void func_switch() {
    int i = 0;
    switch (i) {
        case 0:
            int j = i + 10; /* そもそもswitch分の中の変数定義はビルドエラー */
            printf("number_j: %d\n", j);
            break;
        default: /* -Wjump-misses-initの警告が出る */
            printf("number_i: %d\n", i);
            break;
    }
}
#endif

void Wjump_misses_init() {
    func_goto();
    // func_switch();
}
