#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, K, ans[MAXN][3];

vector<int> e[MAXN], v[MAXN];
int dis[2][MAXN];
pii from[MAXN];

vector<pii> vec;

int bfs(int S, int *dis) {
    for (int i = 0; i < n; i++) dis[i] = -1;
    queue<int> q;
    q.push(S); dis[S] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i], idx = v[sn][i];
            if (dis[fn] >= 0) continue;
            q.push(fn); dis[fn] = dis[sn] + 1; from[fn] = {sn, idx};
        }
    }

    int ret = S;
    for (int i = 0; i < n; i++) if (dis[i] > dis[ret]) ret = i;
    return ret;
}

void dfs(int sn, int fa, int now, int det) {
    bool leaf = true;
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i], idx = v[sn][i];
        if (fn == fa) continue;
        leaf = false;
        if (ans[idx][0] == -1) ans[idx][0] = now;
        vec.push_back({sn, idx});
        dfs(fn, sn, (now + det + K) % K, det);
        vec.pop_back();
    }

    if (leaf) for (int i = vec.size() - 1; i >= 0; i--) {
        int idx = vec[i].second;
        if (ans[idx][1] >= 0) break;
        if (vec.size() - i <= K) ans[idx][1] = vec[vec.size() - K].first, ans[idx][2] = sn;
        else ans[idx][1] = vec[i].first, ans[idx][2] = vec[i + K].first;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); v[x].push_back(i);
        e[y].push_back(x); v[y].push_back(i);
        for (int j = 0; j < 3; j++) ans[i][j] = -1;
    }

    int u = bfs(0, dis[0]);
    int v = bfs(u, dis[0]);
    bfs(v, dis[1]);

    K = n;
    for (int i = 0; i < n; i++) if (e[i].size() == 1) K = min(K, max(dis[0][i], dis[1][i]));
    vector<pii> diam;
    diam.push_back({u, 0});
    for (int sn = u; sn != v; sn = from[sn].first) diam.push_back(from[sn]);
    for (int i = 1; i < diam.size(); i++) {
        int idx = diam[i].second;
        ans[idx][0] = (i - 1) % K;
        if (i <= K) ans[idx][1] = diam[0].first, ans[idx][2] = diam[K].first;
        else ans[idx][1] = diam[i - K].first, ans[idx][2] = diam[i].first;
    }

    int mid = diam.size() / 2, x = diam[mid].first, y = diam[mid - 1].first;
    for (int i = 0; i < mid; i++) vec.push_back({diam[i].first, diam[i + 1].second});
    dfs(x, y, mid % K, 1);
    vec.clear();
    for (int i = diam.size() - 1; i >= mid; i--) vec.push_back(diam[i]);
    dfs(y, x, (mid - 2 % K + K) % K, -1);

    printf("%d\n", K);
    for (int i = 1; i < n; i++) for (int j = 0; j < 3; j++) printf("%d%c", ans[i][j], "\n "[j < 2]);
    return 0;
}
