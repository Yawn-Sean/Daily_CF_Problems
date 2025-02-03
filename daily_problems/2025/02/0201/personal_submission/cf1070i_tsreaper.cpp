#include <bits/stdc++.h>
#define MAXN 600
#define MAXM 600
#define INF ((int) 1e9)
using namespace std;

int n, m, K, ans[MAXM + 5];

int deg[MAXN + 5];

struct Edge {
    int fn, nxt, cap;
} e[(MAXN + MAXM * 3) * 2 + 5];
int S, T, eid, p[MAXN + MAXM + 5];
int dep[MAXN + MAXM + 5], cur[MAXN + MAXM + 5];

void adde(int sn, int fn, int cap) {
    e[eid] = { fn, p[sn], cap }; p[sn] = eid++;
    e[eid] = { sn, p[fn], 0 }; p[fn] = eid++;
}

bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof(int) * (T + 1));

    dep[S] = 1;
    q.push(S);
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = p[sn]; i >= 0; i = e[i].nxt) {
            int fn = e[i].fn;
            if (dep[fn] == 0 && e[i].cap > 0) {
                dep[fn] = dep[sn] + 1;
                q.push(fn);
            }
        }
    }
    return dep[T];
}

int dfs(int sn, int flow) {
    if (sn == T || flow == 0) return flow;
    int ret = 0;
    for (int &i = cur[sn]; i >= 0; i = e[i].nxt) {
        int fn = e[i].fn;
        if (dep[fn] == dep[sn] + 1) {
            int d = dfs(fn, min(flow - ret, e[i].cap));
            if (d == 0) continue;
            ret += d;
            e[i].cap -= d;
            e[i ^ 1].cap += d;
            if (ret == flow) return ret;
        }
    }
    return ret;
}

void solve() {
    scanf("%d%d%d", &n, &m, &K);

    for (int i = 1; i <= n; i++) deg[i] = 0;
    S = 0; T = n + m + 1;
    eid = 0;
    for (int i = S; i <= T; i++) p[i] = -1;
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        deg[x]++; deg[y]++;
        adde(x, n + i, 1);
        adde(y, n + i, 1);
    }

    int need = 0;
    for (int i = 1; i <= n; i++) if (deg[i] > K) {
        int cap = 2 * (deg[i] - K);
        adde(S, i, cap);
        need += cap;
    }
    for (int i = 1; i <= m; i++) adde(n + i, T, 1);

    int mf = 0;
    while (bfs()) {
        memcpy(cur, p, sizeof(int) * (T + 1));
        mf += dfs(S, INF);
    }
    if (mf != need) {
        for (int i = 1; i <= m; i++) printf("0%c", "\n "[i < m]);
        return;
    }

    int idx = 0;
    memset(ans, 0, sizeof(int) * (m + 3));
    for (int sn = 1; sn <= n; sn++) {
        vector<int> vec;
        for (int i = p[sn]; i >= 0; i = e[i].nxt) {
            int t = e[i].fn - n;
            if (t < 1 || t > m) continue;
            if (e[i].cap > 0) { if (ans[t] == 0) ans[t] = ++idx; }
            else vec.push_back(t);
        }
        for (int i = 0; i < vec.size(); i += 2) ans[vec[i]] = ans[vec[i + 1]] = ++idx;
    }
    for (int i = 1; i <= m; i++) printf("%d%c", ans[i], "\n "[i < m]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
