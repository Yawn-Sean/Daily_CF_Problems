#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE
#include "test.h"
#else
#define debug(...) 42
#define debug_assert(...) 42
#endif


#define IOS ios::sync_with_stdio(0),cin.tie(0)

using ll = long long;
using ull = unsigned long long;

#define endl '\n'
#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int inf = 1e18;
const int mod = 1e9 + 7;

struct DSU {
    vector<int> fa;

    explicit DSU(int n): fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        debug(x, fa[x]);
        if (fa[x] == x)
            return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        fa[x] = y;
    }

    int count() {
        int x = 0;
        for (int i = 1; i < fa.size(); i++) {
            if (i == fa[i])x++;
        }
        return x;
    }
};

void init() {
}


void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    DSU d(n + m);
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        d.merge(x, n + y);
    }
    cout << d.count() - 1;
}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
