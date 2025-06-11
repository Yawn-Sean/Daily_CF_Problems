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

    string s;
    cin >> s;

    int n = s.size();
    bool flg = false;

    for (int i = 1; i < n / 2; i ++) {
        if (s[i] != s[i - 1]) {
            flg = true;
        }
    }

    for (int i = n - n / 2; i < n - 1; i ++) {
        if (s[i] != s[i + 1]) {
            flg = true;
        }
    }

    if (!flg) cout << "Impossible";
    else {
        while (s.size() % 2 == 0) {
            string v = s.substr(0, s.size() / 2), v1 = v;
            reverse(v1.begin(), v1.end());
            if (v != v1) return cout << 1, 0;
            s = v;
        }
        cout << 2;
    }

    return 0;
}