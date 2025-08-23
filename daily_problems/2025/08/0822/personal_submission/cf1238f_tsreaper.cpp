#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, ans;
vector<int> e[MAXN + 5];

int dfs(int sn, int fa) {
    int deg = e[sn].size();
    ans = max(ans, deg + 1);

    int mx = 0;
    for (int fn : e[sn]) if (fn != fa) {
        int t = dfs(fn, sn);
        ans = max(ans, deg + t);
        ans = max(ans, deg + t + mx - 1);
        mx = max(mx, t);
    }

    return max(deg, mx + deg - 1);
}

void solve() {
    scanf("%d", &n);

    ans = 0;
    for (int i = 1; i <= n; i++) e[i].clear();

    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    dfs(1, 0);
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
