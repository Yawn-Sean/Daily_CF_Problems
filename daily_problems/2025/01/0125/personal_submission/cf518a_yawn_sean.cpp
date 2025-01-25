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

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();

    for (int i = 0; i < n; i ++) {
        if (s1[i] != s2[i]) {
            bool flg = false;

            for (int j = i + 1; j < n; j ++) {
                if (s1[j] != 'z') {
                    flg = true;
                }
            }

            if (flg) cout << s1.substr(0, i + 1) << string(n - i - 1, 'z');
            else {
                string ans = s1.substr(0, i) + (char)(s1[i] + 1) + string(n - i - 1, 'a');
                cout << (ans < s2 ? ans : "No such string");
            }

            return 0;
        }
    }

    return 0;
}