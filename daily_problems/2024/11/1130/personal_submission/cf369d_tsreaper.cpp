#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;
typedef pair<int, int> pii;

int n, K, ans;

int f[MAXN + 5], g[MAXN + 5], dis[MAXN + 5][MAXN + 5];

void bfs() {
    for (int i = 1; i <= n + 1; i++) for (int j = i + 1; j <= n + 2; j++) dis[i][j] = -1;
    queue<pii> q;
    q.push({1, 2}); dis[1][2] = 0;
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int i = p.first, j = p.second;
        if (j > n) continue;

        auto update = [&](int ii, int jj) {
            if (dis[ii][jj] >= 0) return;
            q.push({ii, jj});
            dis[ii][jj] = dis[i][j] + 1;
        };

        if (g[n] - g[j - 1] == 0 && f[i] - f[i - 1] == 0) update(i, j + 1);
        if (f[n] - f[j - 1] < n - j + 1 && g[i] - g[i - 1] == 0) update(j, j + 1);
        if (f[n] - f[j - 1] < n - j + 1 && f[i] - f[i - 1] == 0) update(j + 1, j + 2);
    }
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x == 0) f[i] = 1;
        else if (x == 100) g[i] = 1;
        f[i] += f[i - 1]; g[i] += g[i - 1];
    }
    bfs();
    for (int i = 1; i <= n + 1; i++) for (int j = i + 1; j <= n + 2; j++) if (dis[i][j] >= 0 && dis[i][j] <= K) ans++;
    printf("%d\n", ans);
    return 0;
}
