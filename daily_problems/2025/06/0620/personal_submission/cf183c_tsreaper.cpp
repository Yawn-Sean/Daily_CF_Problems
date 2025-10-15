#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m;

vector<int> e[MAXN + 5], v[MAXN + 5];
int dis[MAXN + 5], col[MAXN + 5];

int bfs(int S) {
    queue<int> q;
    q.push(S); dis[S] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            if (dis[fn] <= n) {
                int det = abs(dis[sn] + v[sn][i] - dis[fn]);
                if (det > 0) return det;
                continue;
            }
            q.push(fn); dis[fn] = dis[sn] + v[sn][i];
        }
    }
    return 0;
}

bool test(int K) {
    for (int i = 1; i <= n; i++) col[i] = -1;
    for (int S = 1; S <= n; S++) if (col[S] == -1) {
        col[S] = 0;
        queue<int> q; q.push(S);
        while (!q.empty()) {
            int sn = q.front(); q.pop();
            for (int i = 0; i < e[sn].size(); i++) {
                int fn = e[sn][i];
                int c = (col[sn] + v[sn][i] + K) % K;
                if (col[fn] >= 0) {
                    if (col[fn] != c) return false;
                    continue;
                }
                q.push(fn); col[fn] = c;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); v[x].push_back(1);
        e[y].push_back(x); v[y].push_back(-1);
    }

    for (int i = 1; i <= n; i++) dis[i] = n + 1;
    for (int i = 1; i <= n; i++) if (dis[i] > n) {
        int t = bfs(i);
        if (t > 0) {
            for (int j = t; j > 1; j--) if (t % j == 0 && test(j)) { printf("%d\n", j); exit(0); }
            printf("1\n"); exit(0);
        }
    }
    printf("%d\n", n);
    return 0;
}
