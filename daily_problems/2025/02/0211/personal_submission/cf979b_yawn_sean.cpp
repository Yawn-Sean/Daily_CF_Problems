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

    auto f = [&] () -> int {
        string s;
        cin >> s;
        
        int k = s.size(), c = 0;
        map<char, int> mp;

        for (auto &x: s) {
            if (mp[x] == c) c ++;
            mp[x] ++;
        }

        if (c + n <= k) return c + n;
        if (c == k && n == 1) return max(1, k - 1);
        return k;
    };

    int v1 = f(), v2 = f(), v3 = f();

    if (v1 > v2 && v1 > v3) cout << "Kuro";
    else if (v2 > v1 && v2 > v3) cout << "Shiro";
    else if (v3 > v1 && v3 > v2) cout << "Katie";
    else cout << "Draw";

    return 0;
}