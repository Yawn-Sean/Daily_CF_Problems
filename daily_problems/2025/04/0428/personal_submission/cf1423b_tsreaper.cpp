#include <bits/stdc++.h>
#define MAXN ((int) 1e4)
#define MAXM ((int) 1e5)
using namespace std;

int n, m, E[MAXM + 5][3];

struct Edge {
    int fn, nxt, cap;
};
vector<Edge> e;
int S, T, p[MAXN * 2 + 5], dep[MAXN * 2 + 5], cur[MAXN * 2 + 5];

void adde(int sn, int fn) {
    int idx = e.size();
    e.push_back({fn, p[sn], 1});
    p[sn] = idx;
    idx = e.size();
    e.push_back({sn, p[fn], 0});
    p[fn] = idx;
}

bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof(int) * (T + 1));
    q.push(S); dep[S] = 1;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = p[sn]; i >= 0; i = e[i].nxt) {
            int fn = e[i].fn;
            if (dep[fn] == 0 && e[i].cap > 0) {
                q.push(fn);
                dep[fn] = dep[sn] + 1;
            }
        }
    }
    return dep[T] > 0;
}

int dfs(int sn, int flow) {
    if (sn == T || flow == 0) return flow;
    int ret = 0;
    for (int &i = cur[sn]; i >= 0; i = e[i].nxt) {
        int fn = e[i].fn;
        if (dep[fn] == dep[sn] + 1) {
            int d = dfs(fn, min(flow - ret, e[i].cap));
            if (d > 0) {
                ret += d;
                e[i].cap -= d;
                e[i ^ 1].cap += d;
                if (ret == flow) return ret;
            }
        }
    }
    return ret;
}

bool check(int lim) {
    S = 0; T = n * 2 + 1;
    memset(p, -1, sizeof(int) * (T + 1));
    for (int i = 1; i <= n; i++) adde(S, i), adde(n + i, T);
    for (int i = 1; i <= m; i++) if (E[i][2] <= lim) adde(E[i][0], n + E[i][1]);

    int flow = 0;
    while (bfs()) {
        memcpy(cur, p, sizeof(int) * (T + 1));
        flow += dfs(S, 1e9);
    }
    return flow == n;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) for (int j = 0; j < 3; j++) scanf("%d", &E[i][j]);

    if (!check(1e9)) { printf("-1\n"); return 0; }
    int head = 1, tail = 1e9;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head);
    return 0;
}
