#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, A[MAXN + 5];

vector<int> e[MAXN + 5], E[MAXN + 5];
bool vis[2][MAXN + 5];

void bfs(vector<int> *e, bool *vis, int K) {
    queue<int> q;
    for (int i = 1; i <= n; i++) if (A[i] == K)
        q.push(i), vis[i] = true;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) if (!vis[fn]) {
            vis[fn] = true;
            if (A[fn] != 1) q.push(fn);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); E[y].push_back(x);
    }

    bfs(e, vis[0], 1);
    bfs(E, vis[1], 2);
    for (int i = 1; i <= n; i++)
        if (vis[0][i] && vis[1][i]) printf("1\n");
        else printf("0\n");
    return 0;
}
