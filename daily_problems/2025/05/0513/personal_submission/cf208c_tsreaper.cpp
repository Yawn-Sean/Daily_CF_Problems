#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m;
double ans;

vector<int> e[MAXN + 5];
int dis[2][MAXN + 5];
long long f[2][MAXN + 5];

void bfs(int S, int *dis, long long *f) {
    for (int i = 1; i <= n; i++) dis[i] = -1;
    queue<int> q;
    q.push(S); dis[S] = 0; f[S] = 1;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) {
            if (dis[fn] < 0) q.push(fn), dis[fn] = dis[sn] + 1;
            else if (dis[sn] == dis[fn] + 1) f[sn] += f[fn];
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    bfs(1, dis[0], f[0]);
    bfs(n, dis[1], f[1]);

    ans = 1;
    for (int i = 2; i < n; i++) if (dis[0][i] + dis[1][i] == dis[0][n]) {
        long long t = f[0][i] * f[1][i];
        ans = max(ans, 2.0 * t / f[0][n]);
    }
    printf("%.12f\n", ans);
    return 0;
}
