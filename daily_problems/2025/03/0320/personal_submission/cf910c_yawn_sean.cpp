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

    vector<int> weight(10, 0), start(10, 0);

    while (n --) {
        string s;
        cin >> s;

        start[s[0] - 'a'] = 1;
        int k = s.size(), cur = 1;

        for (int i = k - 1; i >= 0; i --) {
            weight[s[i] - 'a'] += cur;
            cur *= 10;
        }
    }

    vector<int> order(10), used(10, 0);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return weight[i] > weight[j];});

    int ans = 0;
    for (int i = 0; i < 10; i ++) {
        for (auto &x: order) {
            if (!used[x] && (i || !start[x])) {
                used[x] = 1;
                ans += i * weight[x];
                break;
            }
        }
    }

    cout << ans;

    return 0;
}