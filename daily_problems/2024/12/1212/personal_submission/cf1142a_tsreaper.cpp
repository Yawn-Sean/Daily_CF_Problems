#include <bits/stdc++.h>
using namespace std;

int n, K, X, Y;
long long ans1, ans2;

void gao(int x, int y) {
    long long len = 1LL * n * K;
    for (int i = 0; i < n; i++) {
        long long d = (1LL * i * K + y - x + len) % len;
        for (int j = 0; j < 2; j++) {
            long long g = len / gcd(len, d);
            ans1 = min(ans1, g); ans2 = max(ans2, g);
            d = (len - d) % len;
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &K, &X, &Y);
    ans1 = 1e18;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
        gao(i ? X : (K - X) % K, j ? Y : (K - Y) % K);
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}
