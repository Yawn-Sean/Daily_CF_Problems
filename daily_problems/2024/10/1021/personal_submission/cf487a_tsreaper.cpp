#include <bits/stdc++.h>
using namespace std;

int main() {
    int Y[3], M[3], P[3];
    for (int i = 0; i < 3; i++) scanf("%d", &Y[i]);
    for (int i = 0; i < 3; i++) scanf("%d", &M[i]);
    for (int i = 0; i < 3; i++) scanf("%d", &P[i]);

    long long ans = 1e18;
    for (int i = 0; i <= 200; i++) {
        int a = Y[1] + i - M[2];
        if (a <= 0) continue;
        int t = (M[0] + a - 1) / a;
        for (int j = 0; j <= 100; j++) {
            int b = M[1] - (Y[2] + j);
            long long base = P[1] * i + P[2] * j;
            if (b <= 0) ans = min(ans, base);
            int need = t * b + 1;
            ans = min(ans, base + 1LL * max(0, need - Y[0]) * P[0]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
