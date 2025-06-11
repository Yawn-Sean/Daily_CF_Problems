#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divide, I conquer!
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> pts(n);
    for (auto &[x, y]: pts)
        cin >> x >> y;
    
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i ++)
        mp[pts[i]] = i;
    
    vector<int> used(n);
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2; 

    auto find_support = [&] (int x, int y) -> int {
        int cnt = 0;
        for (int dx = -1; dx < 2; dx ++) {
            if (mp.find({x + dx, y - 1}) != mp.end()) {
                cnt ++;
            }
        }
        return cnt;
    };

    auto check = [&] (int x, int y) -> bool {
        if (mp.find({x, y}) == mp.end()) return false;
        for (int dx = -1; dx < 2; dx ++) {
            if (mp.find({x + dx, y + 1}) != mp.end() && find_support(x + dx, y + 1) == 1) {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < n; i ++) {
        if (check(pts[i].first, pts[i].second)) {
            pq1.push(i);
            pq2.push(i);
        }
    }

    int ans = 0, mod = 1e9 + 9;

    for (int i = 0; i < n; i ++) {
        while (true) {
            int u;
            if (i % 2 == 0) {
                while (used[pq1.top()]) pq1.pop();
                u = pq1.top(), pq1.pop();
            }
            else {
                while (used[pq2.top()]) pq2.pop();
                u = pq2.top(), pq2.pop();
            }

            auto &[x, y] = pts[u];

            if (check(x, y)) {
                ans = (1ll * ans * n + u) % mod;
                used[u] = 1;
                mp.erase(pts[u]);

                for (int dx = -1; dx < 2; dx ++) {
                    if (check(x + dx, y - 1)) {
                        int v = mp[{x + dx, y - 1}];
                        pq1.push(v);
                        pq2.push(v);
                    }
                }
                break;
            }
        }
    }

    cout << ans;

    return 0;
}