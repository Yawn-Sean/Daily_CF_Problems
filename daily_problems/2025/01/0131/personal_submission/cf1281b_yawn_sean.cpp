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

    int t;
    cin >> t;

    while (t --) {
        string s1, s2;
        cin >> s1 >> s2;

        int k = s1.size(), a = 0, b = 0, pos = k - 1;
        for (int i = k - 2; i >= 0; i --) {
            if (s1[i] < s1[pos]) pos = i;
            else if (s1[i] > s1[pos]) a = i, b = pos;
        }

        swap(s1[a], s1[b]);
        cout << (s1 < s2 ? s1 : "---") << '\n';
    }

    return 0;
}