#include <bits/stdc++.h>
#define MAXN 100
#define MAXA ((int) 1e6)
using namespace std;

int n, m, A[MAXN + 5];
long long ans[MAXN + 5];

struct Edge {
    int fn, g, l;
};
vector<Edge> e[MAXN + 5];
int vis[MAXN + 5];

bool check(int S, int X) {
    queue<int> q;
    q.push(S); vis[S] = X; ans[S] = X;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        if (ans[sn] == 0) return false;
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i].fn;
            if (vis[fn] == X) continue;
            q.push(fn); vis[fn] = X; ans[fn] = 1LL * e[sn][i].g * e[sn][i].l / ans[sn];
        }
    }

    q.push(S); vis[S] = -1;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i].fn;
            long long g = gcd(ans[sn], ans[fn]);
            if (ans[sn] > e[sn][i].l || ans[fn] > e[sn][i].l || e[sn][i].g != g || e[sn][i].l != ans[sn] * ans[fn] / g) return false;
            if (vis[fn] == -1) continue;
            q.push(fn); vis[fn] = -1;
        }
    }

    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y, g, l; scanf("%d%d%d%d", &x, &y, &g, &l);
        e[x].push_back({y, g, l});
        e[y].push_back({x, g, l});
        A[x] = gcd(A[x], l);
        A[y] = gcd(A[y], l);
    }

    for (int i = 1; i <= n; i++) if (vis[i] == 0) {
        if (A[i] == 0) { ans[i] = 1; vis[i] = 1; continue; }
        bool failed = true;
        for (int x = 1; x * x <= A[i]; x++) if (check(i, x) || check(i, A[i] / x)) { failed = false; break; }
        if (failed) { printf("NO\n"); return 0; }
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%lld%c", ans[i], "\n "[i < n]);
    return 0;
}
