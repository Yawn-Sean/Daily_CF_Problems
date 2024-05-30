#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
vector<int> g[N];
vector<pair<int, int>> ng[N];
int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], cnt;
int din[N], dout[N];
vector<array<int, 3>> edge(N);
void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    stk[++top] = x, instk[x] = 1;
    for (int y : g[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
        int y;
        ++cnt;
        do {
            y = stk[top--];
            instk[y] = 0;
            scc[y] = cnt;
        } while (y != x);
    }
}
const int M = 1e5;
ll f[N];
ll pre[N];
ll sum[N];
ll dis[N];

void dfs(int st) {
    dis[st] = sum[st];
    queue<int> q;
    for (int i = 1; i <= cnt; i++)
        if (!din[i]) q.push(i);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto [y, w] : ng[x]) {
            if (dis[x] >= 0)
                dis[y] = max(dis[y], dis[x] + w + sum[y]);
            din[y]--;
            if (!din[y]) q.push(y);
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= M; i++) {
        f[i] = 1ll * i * (i - 1) / 2;
        pre[i] = pre[i - 1] + f[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back(y);
        edge[i] = {x, y, w};
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= m; i++) {
        int x = edge[i][0], y = edge[i][1], w = edge[i][2];
        if (scc[x] != scc[y]) {
            ng[scc[x]].push_back({scc[y], w});
            din[scc[y]]++;
            dout[scc[x]]++;
        } else {
            int pos = upper_bound(f + 1, f + 1 + M, w) - f - 1;
            sum[scc[x]] += 1ll * w * pos - pre[pos];
        }
    }
    int s;
    cin >> s;
    memset(dis, -1, sizeof dis);
    dfs(scc[s]);
    ll ans = 0;
    for (int i = 1; i <= cnt; i++) {
        ans = max(ans, dis[i]);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}