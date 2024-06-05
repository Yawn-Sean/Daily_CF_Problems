#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
struct dsu {
    vector<int> pa, size;
    int conn;
    explicit dsu(int size_) : pa(size_), size(size_, 1) {
        iota(pa.begin(), pa.end(), 0);
        conn = size_;
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        pa[y] = x;
        size[x] += size[y];
        conn--;
    }
    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
    int count() {
        return conn;
    }
};
void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> g[n + 1];
    vector<int> t0;
    dsu ds(n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);
        if (x == 0) {
            t0.push_back(y);
        } else {
            g[x].push_back(y);
            g[y].push_back(x);
            ds.unite(x, y);
        }
    }
    if (t0.size() < d || d < ds.count() - 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> vis(n);
    for (int i = 0; i < t0.size(); i++) {
        if (vis[ds.find(t0[i])]) continue;
        vis[ds.find(t0[i])] = 1;
        g[0].push_back(t0[i]);
        g[t0[i]].push_back(0);
        t0[i] = -1;
        d--;
    }
    if (d) {
        for (int i = 0; i < t0.size() && d; i++) {
            if (t0[i] == -1) continue;
            g[0].push_back(t0[i]);
            g[t0[i]].push_back(0);
            d--;
        }
    }
    queue<int> q;
    q.push(0);
    vis.assign(n, 0);
    vector<pair<int, int>> ans;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = 1;
        for (int y : g[x]) {
            if (vis[y]) continue;
            vis[y] = 1;
            q.push(y);
            ans.emplace_back(x, y);
        }
    }
    for (auto [x, y] : ans) {
        cout << x + 1 << ' ' << y + 1 << endl;
    }
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