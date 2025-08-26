#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<long long, int> pli;

int n, m, S, T, A[MAXN + 5], B[MAXN + 5];

vector<int> e[MAXN + 5], v[MAXN + 5];
vector<int> E[MAXN + 5], V[MAXN + 5];
long long dis[MAXN + 5];

void dijkstra(int S, vector<int> *e, vector<int> *v) {
    memset(dis, -1, sizeof(long long) * (n + 3));
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, S}); dis[S] = 0;
    while (!pq.empty()) {
        pli p = pq.top(); pq.pop();
        int sn = p.second;
        if (dis[sn] != p.first) continue;
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            long long dd = dis[sn] + v[sn][i];
            if (dis[fn] >= 0 && dis[fn] <= dd) continue;
            pq.push({dd, fn}); dis[fn] = dd;
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); e[y].push_back(x);
        v[x].push_back(z); v[y].push_back(z);
    }
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i], &B[i]);

    for (int i = 1; i <= n; i++) {
        dijkstra(i, e, v);
        for (int j = 1; j <= n; j++) if (dis[j] >= 0 && dis[j] <= A[i])
            E[i].push_back(j), V[i].push_back(B[i]);
    }
    dijkstra(S, E, V);
    printf("%lld\n", dis[T]);
    return 0;
}
