#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K, ans;
vector<int> e[MAXN + 5];

int dis[MAXN + 5];

void dfs(int sn, int fa, int d) {
    dis[sn] = d;
    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn, d + 1);
}

void dfs2(int sn, int fa, int d) {
    if (d <= dis[sn]) ans = max(ans, dis[sn]);
    if (d < dis[sn]) {
        for (int fn : e[sn]) if (fn != fa) dfs2(fn, sn, d + 1);
    }
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    dfs(1, 0, 0);
    dfs2(K, 0, 0);
    printf("%d\n", ans * 2);
    return 0;
}
