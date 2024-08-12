#include <bits/stdc++.h>
#define MAXN 1000
#define INF ((int) 1e9)
using namespace std;

int n, m, S, T, ans;

bool g[MAXN + 10][MAXN + 10];
vector<int> e[MAXN + 10];
int disS[MAXN + 10], disT[MAXN + 10];

void bfs(int S, int *dis) {
    for (int i = 1; i <= n; i++) dis[i] = INF;
    queue<int> q;
    q.push(S); dis[S] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) if (dis[fn] == INF) {
            q.push(fn);
            dis[fn] = dis[sn] + 1;
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        g[x][y] = g[y][x] = true;
        e[x].push_back(y); e[y].push_back(x);
    }

    bfs(S, disS); bfs(T, disT);
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (!g[i][j]) {
        int t = min(disS[i] + disT[j], disS[j] + disT[i]) + 1;
        if (t >= disS[T]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
