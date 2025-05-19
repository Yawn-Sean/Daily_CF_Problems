#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, pii> plii;

int n, m, A[MAXN + 10];

vector<int> e[MAXN + 10], v[MAXN + 10];
long long dis[MAXN + 10][MAXN + 10];

long long dijkstra() {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = -1;

    priority_queue<plii> pq;
    pq.push({0, {1, 1}});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int sn = p.second.first, bike = p.second.second;
        if (dis[sn][bike] >= 0) continue;
        dis[sn][bike] = -p.first;

        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            if (dis[fn][bike] >= 0) continue;
            pq.push({-dis[sn][bike] - 1LL * v[sn][i] * A[bike], {fn, bike}});
        }

        if (dis[sn][sn] >= 0) continue;
        pq.push({-dis[sn][bike], {sn, sn}});
    }

    long long ret = 1e18;
    for (int i = 1; i <= n; i++) if (dis[n][i] >= 0) ret = min(ret, dis[n][i]);
    return ret;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) e[i].clear(), v[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    printf("%lld\n", dijkstra());
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
