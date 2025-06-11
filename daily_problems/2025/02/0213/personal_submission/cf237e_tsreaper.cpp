#include <bits/stdc++.h>
#define MAXN 100
#define MAXLEN 100
#define MAXNODE (MAXN + (MAXN + 1) * 26)
#define INF ((int) 1e9)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 5];
char s[MAXN + 5][MAXLEN + 5];

struct Edge {
    int fn, val, cap, nxt;
};
vector<Edge> e;
int S, T, p[MAXNODE + 5];

int dis[MAXNODE + 5], from[MAXNODE + 5];
bool vis[MAXNODE + 5];

void adde(int sn, int fn, int val, int cap) {
    int idx = e.size();
    e.push_back({fn, val, cap, p[sn]}); p[sn] = idx;
    idx = e.size();
    e.push_back({sn, -val, 0, p[fn]}); p[fn] = idx;
}

pii spfa() {
    queue<int> q;
    for (int i = S; i <= T; i++) dis[i] = INF;
    q.push(S); dis[S] = 0; vis[S] = true;
    while (!q.empty()) {
        int sn = q.front(); q.pop(); vis[sn] = false;
        for (int i = p[sn]; i >= 0; i = e[i].nxt) if (e[i].cap > 0) {
            int fn = e[i].fn;
            if (dis[sn] + e[i].val >= dis[fn]) continue;
            dis[fn] = dis[sn] + e[i].val;
            from[fn] = i;
            if (vis[fn]) continue;
            q.push(fn); vis[fn] = true;
        }
    }

    if (dis[T] == INF) return {0, 0};
    int flow = INF;
    for (int sn = T; sn != S; sn = e[from[sn] ^ 1].fn)
        flow = min(flow, e[from[sn]].cap);
    for (int sn = T; sn != S; sn = e[from[sn] ^ 1].fn) {
        e[from[sn]].cap -= flow;
        e[from[sn] ^ 1].cap += flow;
    }
    return {flow, dis[T]};
}

int main() {
    scanf("%s%d", s[0] + 1, &n);
    for (int i = 1; i <= n; i++) scanf("%s%d", s[i] + 1, &A[i]);

    S = 0; T = n + (n + 1) * 26 + 1;
    for (int i = S; i <= T; i++) p[i] = -1;

    int cnt[26] = {0};
    for (int j = 1; s[0][j]; j++) cnt[s[0][j] - 'a']++;
    for (int j = 0; j < 26; j++) adde(n + j + 1, T, 0, cnt[j]);
    for (int i = 1; i <= n; i++) {
        adde(S, i, i, A[i]);
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; s[i][j]; j++) cnt[s[i][j] - 'a']++;
        for (int j = 0; j < 26; j++) {
            int t = n + i * 26 + j + 1;
            adde(i, t, 0, INF);
            adde(t, n + j + 1, 0, cnt[j]);
        }
    }

    int tot = 0, ans = 0;
    while (true) {
        pii p = spfa();
        if (p.first == 0) break;
        tot += p.first;
        ans += p.first * p.second;
    }
    if (tot < strlen(s[0] + 1)) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
