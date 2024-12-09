#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int target;
    cin >> target;

    string s;
    cin >> s;

    int n = s.size();
    vector<int> cnt(9 * n + 1, 0);

    for (int i = 0; i < n; i ++) {
        int cur = 0;
        for (int j = i; j < n; j ++) {
            cur += s[j] - '0';
            cnt[cur] ++;
        }
    }

    if (target == 0) {
        int v = n * (n + 1) / 2;
        cout << 1ll * v * v - 1ll * (v - cnt[0]) * (v - cnt[0]);
        return 0;
    }

    long long ans = 0;

    for (int i = 1; i <= 9 * n; i ++) {
        if (target % i == 0 && target / i <= 9 * n) {
            ans += 1ll * cnt[i] * cnt[target / i];
        }
    }

    cout << ans;

    return 0;
}