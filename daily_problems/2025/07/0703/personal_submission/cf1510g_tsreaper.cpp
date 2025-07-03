#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, K;
vector<int> ans;

vector<int> e[MAXN + 5];
int f[MAXN + 5], g[MAXN + 5], sz[MAXN + 5];

void dfs1(int sn) {
    f[sn] = g[sn] = sz[sn] = 0;
    for (int fn : e[sn]) {
        dfs1(fn);
        if (f[fn] > f[sn]) f[sn] = f[fn], g[sn] = fn;
        sz[sn] += sz[fn];
    }
    f[sn]++; sz[sn]++;
}

void dfs2(int sn, int rem, bool flag) {
    ans.push_back(sn); rem--;
    if (flag) {
        for (int fn : e[sn]) if (fn != g[sn] && rem > f[g[sn]]) {
            int t = min(rem - f[g[sn]], sz[fn]);
            rem -= t;
            dfs2(fn, t, false);
            ans.push_back(sn);
        }
        if (rem > 0) dfs2(g[sn], rem, true);
    } else {
        for (int fn : e[sn]) if (rem > 0) {
            int t = min(rem, sz[fn]);
            rem -= t;
            dfs2(fn, t, false);
            ans.push_back(sn);
        }
    }
}

void solve() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        e[x].push_back(i);
    }

    dfs1(1);
    ans.clear(); dfs2(1, K, true);
    printf("%d\n", (int) ans.size() - 1);
    for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
