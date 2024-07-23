#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MOD 998244353
using namespace std;

int n;
long long ans;

vector<int> e[MAXN + 10];

long long dfs(int sn, int fa) {
    long long ret = 1;
    for (int fn : e[sn]) if (fn != fa) ret = ret * dfs(fn, sn) % MOD;
    for (int i = 1; i <= e[sn].size(); i++) ret = ret * i % MOD;
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    ans = n;
    for (int fn : e[1]) ans = ans * dfs(fn, 1) % MOD;
    for (int i = 1; i <= e[1].size(); i++) ans = ans * i % MOD;
    printf("%lld\n", ans);
    return 0;
}
