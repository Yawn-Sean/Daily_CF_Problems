#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, m, K, A[MAXN + 5];

vector<int> e[MAXN + 5];
int dis[MAXN + 5];

void bfs() {
    for (int i = 1; i <= n; i++) dis[i] = -1;
    queue<int> q;
    q.push(1); dis[1] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) if (dis[fn] < 0)
            q.push(fn), dis[fn] = dis[sn] + 1;
    }
}

void solve() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= K; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    vector<pii> ans;
    A[0] = 1;
    for (int i = 1; i <= K; i++) {
        int x = A[i], y = A[i - 1];
        if (x != y) {
            ans.push_back({x, y});
            e[x].push_back(y); e[y].push_back(x);
        }
        
    }
    bfs();

    for (int i = 1; i < K; i++) if (dis[A[i]] >= dis[A[i + 1]]) { printf("-1\n"); return; }
    printf("%d\n", ans.size());
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
