#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;

vector<int> e[MAXN + 5];
long long f[MAXN + 5][2];

void dfs(int sn) {
    if (e[sn].empty()) {
        f[sn][0] = f[sn][1] = 1;
        return;
    }

    f[sn][0] = 1; f[sn][1] = 0;
    for (int fn : e[sn]) {
        dfs(fn);
        f[sn][1] = (f[sn][0] * f[fn][1] + f[sn][1] * f[fn][0]) % MOD;
        f[sn][0] = f[sn][0] * f[fn][0] % MOD;
    }
    f[sn][0] = (f[sn][0] + f[sn][1]) % MOD;
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        e[x].push_back(i);
    }
    dfs(1);
    printf("%lld\n", f[1][0]);
    return 0;
}
