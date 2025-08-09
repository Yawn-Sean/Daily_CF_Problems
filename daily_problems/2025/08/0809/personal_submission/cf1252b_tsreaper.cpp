#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;

vector<int> e[MAXN + 5];
long long f[MAXN + 5][3];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

void dfs(int sn, int fa) {
    vector<long long> g2 = {1}, g12 = {1};
    for (int fn : e[sn]) if (fn != fa) {
        dfs(fn, sn);
        g2.push_back(f[fn][2]);
        g12.push_back((f[fn][1] + f[fn][2]) % MOD);
    }
    g2.push_back(1); g12.push_back(1);
    auto h2 = g2, h12 = g12;

    int ch = g2.size() - 2;
    for (int i = 1; i <= ch; i++) {
        g2[i] = g2[i] * g2[i - 1] % MOD;
        g12[i] = g12[i] * g12[i - 1] % MOD;
    }
    for (int i = ch; i > 0; i--) {
        h2[i] = h2[i] * h2[i + 1] % MOD;
        h12[i] = h12[i] * h12[i + 1] % MOD;
    }

    f[sn][0] = f[sn][1] = g2[ch];
    long long t = 0;
    int i = 0;
    for (int fn : e[sn]) if (fn != fa) {
        i++;
        f[sn][0] = (f[sn][0] + g12[i - 1] * h12[i + 1] % MOD * f[fn][0]) % MOD;
        f[sn][1] = (f[sn][1] + g2[i - 1] * h2[i + 1] % MOD * f[fn][0]) % MOD;
        f[sn][2] = (f[sn][2] + t * h12[i + 1] % MOD * f[fn][0]) % MOD;
        t = (t * (f[fn][1] + f[fn][2]) + g12[i - 1] * f[fn][0]) % MOD;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    dfs(1, 0);
    printf("%lld\n", (f[1][1] + f[1][2]) % MOD);
    return 0;
}
