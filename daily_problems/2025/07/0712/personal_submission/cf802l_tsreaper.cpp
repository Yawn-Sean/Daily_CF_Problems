#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;
typedef pair<long long, long long> pll;

int n;

vector<int> e[MAXN + 5], v[MAXN + 5];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

pll dfs(int sn, int fa, int fv) {
    if (e[sn].size() == 1) return {0, 0};

    long long K = e[sn].size(), B = fv;
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        pll p = dfs(fn, sn, v[sn][i]);
        K = (K - p.first + MOD) % MOD;
        B = (B + p.second + v[sn][i]) % MOD;
    }

    long long inv = power(K, MOD - 2);
    return {inv, B * inv % MOD};
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }

    long long K = e[0].size(), B = 0;
    for (int i = 0; i < e[0].size(); i++) {
        pll p = dfs(e[0][i], 0, v[0][i]);
        K = (K - p.first + MOD) % MOD;
        B = (B + p.second + v[0][i]) % MOD;
    }
    printf("%lld\n", B * power(K, MOD - 2) % MOD);
    return 0;
}
