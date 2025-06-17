#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((long long) 1e18)
using namespace std;

int n, m, K;
long long ans;
bool flag[MAXN + 5];

vector<int> e[MAXN + 5], v[MAXN + 5];
long long dis[2][MAXN * 2 + 5];

void dijkstra(int S, long long *dis) {
    for (int i = 1; i <= n; i++) dis[i * 2] = dis[i * 2 + 1] = INF;
    priority_queue<array<long long, 3>> pq;
    pq.push({0, S, 0});
    while (!pq.empty()) {
        auto arr = pq.top(); pq.pop();
        int sn = arr[1], h = arr[2];
        if (dis[sn * 2 + h] < INF) continue;
        dis[sn * 2 + h] = -arr[0];
        
        auto update = [&](int fn, int hh, int val) {
            int idx = fn * 2 + hh;
            if (dis[idx] < INF) return;
            pq.push({arr[0] - val, fn, hh});
        };

        if (flag[sn]) update(sn, 1, 0);
        for (int i = 0; i < e[sn].size(); i++) update(e[sn][i], h, v[sn][i] / (h + 1));
    }
}

void solve() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) flag[i] = false;
    for (int i = 1; i <= K; i++) {
        int x; scanf("%d", &x);
        flag[x] = true;
    }
    for (int i = 1; i <= n; i++) e[i].clear(), v[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }

    dijkstra(1, dis[0]); dijkstra(n, dis[1]);
    ans = INF;
    for (int i = 1; i <= n; i++) {
        long long x = min(dis[0][i * 2], dis[0][i * 2 + 1]);
        long long y = min(dis[1][i * 2], dis[1][i * 2 + 1]);
        long long t = max(x, y);
        ans = min(ans, t);
    }
    if (ans < INF) printf("%lld\n", ans);
    else printf("-1\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
