#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using a2 = array<int, 2>;
using node = array<int, 3>;
//cout << fixed << setprecision(7) << ans << endl;
const int mod = 998244353, INF = INT_MAX;
const LL inf = LONG_LONG_MAX;
const int N = 2e5 + 10;
int n, m, k;
vector<node> e;

// DSU dsu(n)就行 下标从1开始 
struct DSU {
    std::vector<int> fa, sz;
    int cnt;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        fa.resize(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
        sz.assign(n + 1, 1);
        cnt = n;
    }

    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    // 合并 将x合并到y
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        sz[y] += sz[x];
        fa[x] = y;
        cnt --;
        return true;
    }
    
    int size(int x) {
        return sz[find(x)];
    }
};

LL kruskal() {
    DSU dsu(n);
    sort(e.begin(), e.end());
    bool ok = 1;
    LL ans = 0;
    for (auto [w, u, v]: e) {
        if (!dsu.same(u, v)) {
            dsu.merge(u, v);
            if (w > k) {
                ok = 0;
                ans += 1LL * (w - k);
            }
        }
    }
    if (ok) {
        ans = inf;
        for (auto [w, u, v]: e) {
            ans = min(ans, 1LL * abs(w - k));
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m >> k;
    e.clear();
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({w, u, v});
    }
    cout << kruskal() << endl;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t --) solve();
    return 0;
}
