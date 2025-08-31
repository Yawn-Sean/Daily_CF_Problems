#include <bits/stdc++.h>
#define MAGIC 360360
using namespace std;

int f[MAGIC];

int main() {
    long long X, Y;
    int K;
    scanf("%lld%lld%d", &X, &Y, &K);

    for (int i = 1; i < MAGIC; i++) {
        f[i] = f[i - 1] + 1;
        for (int j = 2; j <= K; j++) f[i] = min(f[i], f[i - i % j] + 1);
    }

    long long bX = X / MAGIC, bY = Y / MAGIC;
    long long ans = 0;
    if (bX > bY) {
        ans += f[X % MAGIC] + (f[MAGIC - 1] + 1) * (bX - bY - 1) + 1;
        X = bY * MAGIC + MAGIC - 1;
    }

    while (X > Y) {
        long long nxt = X - 1;
        for (int j = 2; j <= K; j++) {
            long long t = X - X % j;
            if (t >= Y && t < nxt) nxt = t;
        }
        X = nxt;
        ans++;
    }
    printf("%lld\n", ans);
    return 0;
}
