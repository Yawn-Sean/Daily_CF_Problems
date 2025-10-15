#include <bits/stdc++.h>
#define MAXA (1 << 10)
using namespace std;

int n, K, X;
int cnt[2][MAXA];

int main() {
    scanf("%d%d%d", &n, &K, &X);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[0][x]++;
    }
    
    for (int i = 1; i <= K; i++) {
        memset(cnt[i & 1], 0, sizeof(cnt[i & 1]));
        for (int j = 0, now = 0; j < MAXA; j++) {
            int old = cnt[i & 1 ^ 1][j];
            int t = (old + (now ^ 1)) / 2;
            cnt[i & 1][j] += old - t;
            cnt[i & 1][j ^ X] += t;
            now ^= old & 1;
        }
    }

    int mx = 0, mn = MAXA;
    for (int i = 0; i < MAXA; i++) if (cnt[K & 1][i]) mx = max(mx, i), mn = min(mn, i);
    printf("%d %d\n", mx, mn);
    return 0;
}
