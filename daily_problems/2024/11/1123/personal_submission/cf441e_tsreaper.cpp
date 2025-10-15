#include <bits/stdc++.h>
#define MAXK 200
#define MAGIC 8
using namespace std;
typedef double db;

int K, P;

db f[MAXK + 5][1 << MAGIC][2][MAXK + 55];

db dp(int stp, int msk, int v, int cnt) {
    if (stp == K) {
        if (msk > 0) return __lg(msk & (-msk));
        else return v == 0 ? cnt + MAGIC : MAGIC;
    }
    db &ret = f[stp][msk][v][cnt];
    if (ret >= 0) return ret;
    ret = 0;

    int nxt = (msk << 1) & ((1 << MAGIC) - 1), t = msk >> (MAGIC - 1);
    ret += dp(stp + 1, nxt, t, (t == v ? cnt : 0) + 1) * P / 100.0;

    nxt = (msk + 1) & ((1 << MAGIC) - 1);
    if (nxt == 0) {
        if (v == 0) ret += dp(stp + 1, 0, 1, 1) * (100 - P) / 100.0;
        else ret += dp(stp + 1, 0, 0, cnt) * (100 - P) / 100.0;
    } else {
        ret += dp(stp + 1, nxt, v, cnt) * (100 - P) / 100.0;
    }

    return ret;
}

int main() {
    int x; scanf("%d%d%d", &x, &K, &P);
    for (int i = 0; i <= K; i++) for (int j = 0; j < (1 << MAGIC); j++) for (int k = 0; k <= K + 50; k++)
        f[i][j][0][k] = f[i][j][1][k] = -1;

    int t = x >> MAGIC, a, b = 0;
    if (x < (1 << MAGIC)) {
        a = 0; b = 1;
    } else if (t & 1) {
        a = 1;
        for (; t & 1; t >>= 1) b++;
    } else {
        a = 0;
        for (; t & 1 ^ 1; t >>= 1) b++;
    }
    printf("%.12f\n", dp(0, x & ((1 << MAGIC) - 1), a, b));
    return 0;
}
