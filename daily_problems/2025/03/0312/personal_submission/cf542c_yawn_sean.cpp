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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> ar(n);
    for (auto &x: ar)
        cin >> x, x --;

    long long ans = 1;
    int mi = 0;
    for (int i = 0; i < n; i ++) {
        vector<int> vis(n, -1);
        vis[i] = 0;
        int cur = i;
        while (true) {
            int ncur = ar[cur];
            if (vis[ncur] != -1) {
                ans = ans / gcd(ans, (vis[cur] + 1 - vis[ncur])) * (vis[cur] + 1 - vis[ncur]);
                mi = max(mi, vis[ncur]);
                break;
            }
            vis[ncur] = vis[cur] + 1;
            cur = ncur;
        }
    }

    long long res = ans;
    while (res < mi) res += ans;

    cout << res;

    return 0;
}