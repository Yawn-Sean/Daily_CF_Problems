#include <bits/stdc++.h>
#define MAXK ((int) 1e5)
using namespace std;

int K;
long long ans1, ans2;

vector<int> e[MAXK * 2 + 10], v[MAXK * 2 + 10];
int sz[MAXK * 2 + 10];

int dfs(int sn, int fa, int val) {
    sz[sn] = 1;
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        sz[sn] += dfs(fn, sn, v[sn][i]);
    }
    ans1 += 1LL * val * (sz[sn] & 1);
    ans2 += 1LL * val * min(sz[sn], K * 2 - sz[sn]);
    return sz[sn];
}

void solve() {
    scanf("%d", &K);
    for (int i = 1; i <= K * 2; i++) e[i].clear(), v[i].clear();
    for (int i = 1; i < K * 2; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); e[y].push_back(x);
        v[x].push_back(z); v[y].push_back(z);
    }
    ans1 = ans2 = 0;
    dfs(1, 0, 0);
    printf("%lld %lld\n", ans1, ans2);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
