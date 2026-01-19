#include <algorithm>
#include <bit>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <stack>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <numbers>
#include <cmath>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MOD = 1e9 + 7;

ll query(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    ll x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

void report(ll m) {
    cout << "! " << m << '\n';
    cout.flush();
}

struct UnionFind {
    int n;
    vector<int> pa;
public:
    UnionFind(int sz) : n(sz), pa(sz) {
        iota(pa.begin(), pa.end(), 0);
    }

    int find(int x) {
        if (pa[x] != x) {
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }

    bool merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        pa[px] = py;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (auto& [u, v, w] : edges) {
        cin >> u >> v >> w;
        u--; v--;
    }
    UnionFind uf1(n), uf2(n);
    for (auto& [u, v, w] : edges) {
        if (w % 2 == 0) uf1.merge(u, v);
    }
    vector<char> ans(m);
    bool even = true;
    for (int i = 0; i < m; i++) {
        auto& [u, v, w] = edges[i];
        if (w % 2 && uf1.merge(u, v)) {
            uf2.merge(u, v);
            ans[i] = 1;
            even = !even;
        }
    }
    if (!even) {
        for (int i = 0; i < m; i++) {
            auto& [u, v, w] = edges[i];
            if (w % 2 && uf2.merge(u, v)) {
                ans[i] = 1;
                even = !even;
                break;
            } 
        }
    }
    if (!even) cout << "NO\n";
    else {
        for (int i = 0; i < m; i++) {
            auto& [u, v, w] = edges[i];
            if (w % 2 == 0 && uf2.merge(u, v)) ans[i] = 1;
        }
        cout << "YES\n";
        for (int i = 0; i < m; i++) {
            if (ans[i] == 1) cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}