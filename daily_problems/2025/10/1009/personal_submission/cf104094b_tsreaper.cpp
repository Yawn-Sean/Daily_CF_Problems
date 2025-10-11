#include  <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((long long) 1e18)
#define MOD ((int) 1e9 + 7)
using namespace std;
typedef pair<long long, int> pli;

int n, m, S, T, E[MAXN + 5][3];
long long L, ans;

vector<int> e[MAXN + 5], v[MAXN + 5];
long long dis[2][MAXN + 5], f[2][MAXN + 5];

void dijkstra(int S, long long *dis, long long *f) {
    for (int i = 1; i <= n; i++) dis[i] = INF, f[i] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, S}); dis[S] = 0; f[S] = 1;
    while (!pq.empty()) {
        pli p = pq.top(); pq.pop();
        int sn = p.second;
        if (dis[sn] != p.first) continue;
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            long long d = dis[sn] + v[sn][i];
            if (dis[fn] > d) pq.push({d, fn}), dis[fn] = d, f[fn] = 0;
            if (dis[fn] == dis[sn] + v[sn][i]) f[fn] = (f[fn] + f[sn]) % MOD;
        }
    }
}

int main() {
    scanf("%d%d%d%d%lld", &n, &m, &S, &T, &L);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 3; j++) scanf("%d", &E[i][j]);
        e[E[i][0]].push_back(E[i][1]); v[E[i][0]].push_back(E[i][2]);
        e[E[i][1]].push_back(E[i][0]); v[E[i][1]].push_back(E[i][2]);
    }

    dijkstra(S, dis[0], f[0]);
    dijkstra(T, dis[1], f[1]);

    if (dis[0][T] == L) ans = f[0][T];
    for (int i = 1; i <= m; i++) {
        int x = E[i][0], y = E[i][1];
        long long d = dis[0][x] + E[i][2] + dis[1][y];
        if (x != T && dis[0][T] == dis[0][x] + dis[1][x] && dis[0][T] != d && d == L)
            ans = (ans + f[0][x] * f[1][y]) % MOD;
        d = dis[0][y] + E[i][2] + dis[1][x];
        if (y != T && dis[0][T] == dis[0][y] + dis[1][y] && dis[0][T] != d && d == L)
            ans = (ans + f[0][y] * f[1][x]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
