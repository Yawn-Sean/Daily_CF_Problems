#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, K, A[MAXN + 5];

vector<int> e[MAXN + 5], E[MAXN + 5];
int dis[MAXN + 5];

void bfs() {
    for (int i = 1; i <= n; i++) dis[i] = -1;
    queue<int> q;
    q.push(A[K]); dis[A[K]] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : E[sn]) if (dis[fn] < 0)
            q.push(fn), dis[fn] = dis[sn] + 1;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); E[y].push_back(x);
    }
    scanf("%d", &K);
    for (int i = 1; i <= K; i++) scanf("%d", &A[i]);

    bfs();
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i < K; i++) {
        int sn = A[i];
        if (dis[sn] - 1 < dis[A[i + 1]]) ans1++, ans2++;
        else {
            for (int fn : e[sn]) if (fn != A[i + 1] && dis[sn] - 1 == dis[fn]) { ans2++; break; }
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
