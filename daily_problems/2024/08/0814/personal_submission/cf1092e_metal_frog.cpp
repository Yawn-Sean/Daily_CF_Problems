#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 1005;
vector<int> tree[N];
bool vis[N];
vector<int> path;
int dis[N], mid;

void dfs(int u, int fa, int d) {
    dis[u] = d;
    vis[u] = true;
    for (int v : tree[u]) {
        if (v == fa) continue;
        dfs(v, u, d + 1);
    }
}

bool findCenter(int u, int fa, int len) {
    path.push_back(u);
    if (dis[u] == len) {
        mid = path[sz(path) / 2];
        return true;
    }
    bool flag = false;
    for (int v : tree[u]) {
        if (v == fa) continue;
        if (findCenter(v, u, len)) {
            flag = true;
        }
        path.pop_back();
    }
    return flag;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    int maxD = -1, maxMiddle = -1;
    vector<pii> middlePoints;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            fill(dis, dis + n, -1);
            dfs(i, -1, 0);
            int u = max_element(dis, dis + n) - dis;
            dfs(u, -1, 0);
            int v = max_element(dis, dis + n) - dis;
            int d = dis[v];
            path.clear();
            findCenter(u, -1, d);
            middlePoints.emplace_back(mid, d);
            if (d > maxD) {
                maxD = d;
                maxMiddle = mid;
            }
            cnt++;
        }
    }
    if (cnt == 1) {
        cout << maxD << endl;
    } else {
        int ans = 0;
        for (int i = 0; i < sz(middlePoints); i++) {
            for (int j = i + 1; j < sz(middlePoints); j++) {
                if (middlePoints[i].first != maxMiddle && middlePoints[j].first != maxMiddle) {
                    int d1 = middlePoints[i].second, d2 = middlePoints[j].second;
                    ans = max(ans, (d1 + 1) / 2 + 2 + (d2 + 1) / 2);
                }
            }
            if (middlePoints[i].first != maxMiddle) {
                ans = max(ans, (maxD + 1) / 2 + 1 + (middlePoints[i].second + 1) / 2);
            }
        }
        ans = max(ans, maxD);
        cout << ans << endl;
        for (auto [center, len] : middlePoints) {
            if (center == maxMiddle) continue;
            cout << maxMiddle + 1 << " " << center + 1 << endl;
        }
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
