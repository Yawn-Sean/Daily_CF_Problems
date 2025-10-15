#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((long long) 1e18)
using namespace std;
typedef pair<long long, int> pli;

int n, m;
long long ans;

struct Edge {
    int fn, val, nxt;
    bool ban;
};
vector<Edge> e;
int p[MAXN + 5], from[MAXN + 5];
long long dis1[MAXN + 5], dis2[MAXN + 5];

void adde(int sn, int fn, int val) {
    int idx = e.size();
    e.push_back({fn, val, p[sn], false});
    p[sn] = idx;
}

long long gao(int x, int y) {
    if (dis1[x] < INF && dis2[y] < INF) return dis1[x] + dis2[y];
    else return INF;
}

void dijkstra(int S, long long *dis) {
    for (int i = 1; i <= n; i++) dis[i] = INF;
    priority_queue<array<long long, 3>> pq;
    pq.push({0, S, -1});
    while (!pq.empty()) {
        auto arr = pq.top(); pq.pop();
        int sn = arr[1];
        if (dis[sn] < INF) continue;
        dis[sn] = -arr[0]; from[sn] = arr[2];
        for (int i = p[sn]; i >= 0; i = e[i].nxt) if (dis[e[i].fn] >= INF)
            pq.push({-dis[sn] - e[i].val, e[i].fn, i});            
    }
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = -1;
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        adde(x, y, z); adde(y, x, z);
    }

    dijkstra(1, dis1);
    if (dis1[n] >= INF) { printf("-1\n"); return 0; }
    for (int sn = n; sn > 1; sn = e[from[sn] ^ 1].fn) e[from[sn]].ban = e[from[sn] ^ 1].ban = true;
    dijkstra(n, dis2);

    ans = INF;
    for (int i = 0; i < e.size(); i++) if (!e[i].ban) {
        int sn = e[i ^ 1].fn, fn = e[i].fn;
        ans = min({ans, gao(sn, fn) + e[i].val, gao(fn, sn) + e[i].val});
    }
    if (ans >= INF) { printf("-1\n"); return 0; }
    printf("%lld\n", dis1[n] + ans);
    return 0;
}
