#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXP 20
#define INF ((long long) 1e18)
using namespace std;

int n, m;

vector<int> e[MAXN + 5], v[MAXN + 5];
long long dis[MAXN + 5];

vector<int> E[MAXN + 5], V[MAXN + 5];
int pa[MAXN + 5][MAXP], dep[MAXN + 5];
long long DIS[MAXN + 5];

void dijkstra() {
    for (int i = 1; i <= n; i++) dis[i] = INF;
    typedef array<long long, 4> a4;
    priority_queue<a4, vector<a4>, greater<a4>> pq;
    pq.push({0, 1, 0, 0}); dis[1] = 0;

    while (!pq.empty()) {
        auto arr = pq.top(); pq.pop();
        int sn = arr[1];
        if (dis[sn] != arr[0]) continue;
        int fn = arr[2], val = arr[3];
        E[sn].push_back(fn); V[sn].push_back(val);
        E[fn].push_back(sn); V[fn].push_back(val);

        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            long long d = dis[sn] + v[sn][i];
            if (dis[fn] > d) pq.push({d, fn, sn, v[sn][i]}), dis[fn] = d;
        }
    }
}

void dfs(int sn, int fa, int d, long long D) {
    dep[sn] = d; DIS[sn] = D;
    pa[sn][0] = fa;
    for (int p = 1; p < MAXP; p++) pa[sn][p] = pa[pa[sn][p - 1]][p - 1];
    for (int i = 0; i < E[sn].size(); i++) {
        int fn = E[sn][i];
        if (fn == fa) continue;
        dfs(fn, sn, d + 1, D + V[sn][i]);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int p = MAXP - 1; p >= 0; p--) if (dep[pa[x][p]] >= dep[y]) x = pa[x][p];
    if (x == y) return x;
    for (int p = MAXP - 1; p >= 0; p--) if (pa[x][p] != pa[y][p]) x = pa[x][p], y = pa[y][p];
    return pa[x][0];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }

    dijkstra();
    dfs(1, 0, 1, 0);
    for (int sn = 1; sn <= n; sn++) for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        int a = lca(sn, fn);
        long long d = DIS[sn] + DIS[fn] - 2 * DIS[a];
        if (d > v[sn][i]) { printf("NO\n"); return 0; }
    }
    printf("YES\n");
    return 0;
}
