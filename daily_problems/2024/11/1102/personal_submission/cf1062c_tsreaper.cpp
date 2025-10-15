#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, q;
char s[MAXN + 10];

int f[MAXN + 10];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%d%d%s", &n, &q, s + 1);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + s[i] - '0';
    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        int len = r - l + 1;
        int w = f[r] - f[l - 1];
        printf("%lld\n", (power(2, len) - power(2, len - w) + MOD) % MOD);
    }
    return 0;
}
