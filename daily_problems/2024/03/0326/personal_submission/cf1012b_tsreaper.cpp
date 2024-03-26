#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXM ((int) 2e5)
using namespace std;

int n, m, K, ans;

vector<int> e[MAXN + MAXM + 10];
bool vis[MAXN + MAXM + 10];

void bfs(int S) {
    queue<int> q;
    q.push(S); vis[S] = true;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) if (!vis[fn]) q.push(fn), vis[fn] = true;
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= K; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(n + y);
        e[n + y].push_back(x);
    }

    for (int i = 1; i <= n + m; i++) if (!vis[i]) bfs(i), ans++;
    printf("%d\n", ans - 1);
    return 0;
}
