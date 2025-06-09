#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m;

vector<int> e[MAXN + 5], v[MAXN + 5];
long long dis[MAXN + 5];
bool vis[MAXN + 5];

void bfs(int S) {
    queue<int> q; q.push(S);
    dis[S] = 0; vis[S] = true;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            if (vis[fn]) continue;
            q.push(fn);
            dis[fn] = dis[sn] + v[sn][i];
            vis[fn] = true;
        }
    }
}

bool solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) e[i].clear(), v[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(-z);
    }

    memset(vis, 0, sizeof(bool) * (n + 3));
    for (int i = 1; i <= n; i++) if (!vis[i]) bfs(i);
    for (int sn = 1; sn <= n; sn++) for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (dis[fn] - dis[sn] != v[sn][i]) return false;
    }
    return true;
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
