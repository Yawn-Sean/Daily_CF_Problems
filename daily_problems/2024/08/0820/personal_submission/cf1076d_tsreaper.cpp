#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define MAXM
using namespace std;

int n, m, K;

struct Edge {
    int fn, val, nxt;
};
vector<Edge> e;
int p[MAXN + 10];

long long dis[MAXN + 10];
bool vis[MAXN + 10];

void adde(int sn, int fn, int val) {
    int idx = e.size();
    e.push_back({fn, val, p[sn]});
    p[sn] = idx;
    idx = e.size();
    e.push_back({sn, val, p[fn]});
    p[fn] = idx;
}

void dijkstra() {
    for (int i = 1; i <= n; i++) dis[i] = -1;
    priority_queue<array<long long, 3>> pq;
    pq.push({0, 1, -1});

    while (!pq.empty() && K > 0) {
        auto arr = pq.top(); pq.pop();
        int sn = arr[1];
        if (dis[sn] >= 0) continue;
        dis[sn] = -arr[0];
        if (arr[2] >= 0) {
            printf("%lld ", arr[2] / 2 + 1);
            K--;
        }

        for (int i = p[sn]; i >= 0; i = e[i].nxt) {
            int fn = e[i].fn;
            if (dis[fn] >= 0) continue;
            pq.push({-dis[sn] - e[i].val, fn, i});
        }
    }
    printf("\n");
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) p[i] = -1;
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        adde(x, y, z);
    }
    
    printf("%d\n", min(K, n - 1));
    dijkstra();
    return 0;
}
