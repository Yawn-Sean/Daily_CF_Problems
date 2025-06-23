#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, T, K;

vector<int> e[MAXN + 5], v[MAXN + 5], pos[MAXN + 5];
int dis[MAXN + 5];

int dijkstra() {
    for (int i = 1; i <= n; i++) dis[i] = -1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({1, 1}); dis[1] = 1;
    while (!pq.empty()) {
        pii p = pq.top(); pq.pop();
        int sn = p.second;
        if (dis[sn] != p.first) continue;
        if (sn == n) return dis[sn] - 1;
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i], val = v[sn][i];
            auto it = lower_bound(pos[val].begin(), pos[val].end(), dis[sn]);
            if (it == pos[val].end()) continue;
            if (dis[fn] != -1 && dis[fn] <= *it + 1) continue;
            pq.push({*it + 1, fn}); dis[fn] = *it + 1;
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= T; i++) {
        int m; scanf("%d", &m);
        for (int j = 1; j <= m; j++) {
            int x, y; scanf("%d%d", &x, &y);
            e[x].push_back(y); v[x].push_back(i);
            e[y].push_back(x); v[y].push_back(i);
        }
    }

    scanf("%d", &K);
    for (int i = 1; i <= K; i++) {
        int x; scanf("%d", &x);
        pos[x].push_back(i);
    }

    printf("%d\n", dijkstra());
    return 0;
}
