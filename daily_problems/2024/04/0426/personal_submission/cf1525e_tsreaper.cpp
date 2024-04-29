#include <bits/stdc++.h>
#define MAXN 20
#define MAXM ((int) 5e4)
#define MOD 998244353
using namespace std;

int n, m, A[MAXN + 10][MAXM + 10];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &A[i][j]);

    long long fac = 1;
    for (int i = 1; i <= n; i++) fac = fac * i % MOD;

    long long ans = 0;
    for (int j = 1; j <= m; j++) {
        vector<int> vec;
        for (int i = 1; i <= n; i++) vec.push_back(A[i][j]);
        sort(vec.begin(), vec.end());
        long long t = 1;
        for (int i = 0; i < vec.size(); i++) t = t * max(0, vec[i] - 1 - i) % MOD;
        ans = (ans + fac - t + MOD) % MOD;
    }
    printf("%lld\n", ans * power(fac, MOD - 2) % MOD);
    return 0;
}
