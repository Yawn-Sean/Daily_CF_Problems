#include <bits/stdc++.h>
#define MAXN 50
#define MAXM 50
#define INF ((int) 1e9)
using namespace std;

int n, m, ans;

struct Edge {
    int fn, cap, val, nxt;
};
vector<Edge> e;
int S, T, p[MAXN + MAXM + 5];

int dis[MAXN + MAXM + 5], from[MAXN + MAXM + 5];
bool inq[MAXN + MAXM + 5];

void adde(int sn, int fn, int cap, int val) {
    int idx = e.size();
    e.push_back({fn, cap, val, p[sn]});
    p[sn] = idx;
    idx = e.size();
    e.push_back({sn, 0, -val, p[fn]});
    p[fn] = idx;
}

int spfa() {
    for (int i = S; i <= T; i++) dis[i] = INF;
    queue<int> q;
    q.push(S); dis[S] = 0; inq[S] = true;
    while (!q.empty()) {
        int sn = q.front(); q.pop(); inq[sn] = false;
        for (int i = p[sn]; i >= 0; i = e[i].nxt) if (e[i].cap) {
            int fn = e[i].fn, dd = dis[sn] + e[i].val;
            if (dis[fn] <= dd) continue;
            dis[fn] = dd; from[fn] = i;
            if (inq[fn]) continue;
            q.push(fn); inq[fn] = true;
        }
    }

    if (dis[T] == INF) return 0;
    int flow = INF;
    for (int now = T; now != S; now = e[from[now] ^ 1].fn) flow = min(flow, e[from[now]].cap);
    for (int now = T; now != S; now = e[from[now] ^ 1].fn) {
        e[from[now]].cap -= flow;
        e[from[now] ^ 1].cap += flow;
        ans += flow * e[from[now]].val;
    }
    return flow;
}

int main() {
    scanf("%d%d", &n, &m);

    S = 0; T = n + m + 1;
    for (int i = S; i <= T; i++) p[i] = -1;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        int x; scanf("%d", &x);
        if (x) ans++, adde(i, j + n, 1, -1);
        else adde(i, j + n, 1, 1);
    }

    int sm1 = 0, sm2 = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        sm1 += x;
        adde(S, i, x, 0);
    }
    for (int j = 1; j <= m; j++) {
        int x; scanf("%d", &x);
        sm2 += x;
        adde(j + n, T, x, 0);
    }
    if (sm1 != sm2) { printf("-1\n"); return 0; }

    int flow = 0;
    while (true) {
        int t = spfa();
        if (t == 0) break;
        flow += t;
    }
    if (flow < max(sm1, sm2)) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
