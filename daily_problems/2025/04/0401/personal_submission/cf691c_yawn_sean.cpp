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

    string s;
    cin >> s;

    string v1, v2;
    bool flg = true;

    for (auto &c: s) {
        if (c == '.') flg = false;
        else if (flg) {
            if (c != '0' || v1.size())
                v1 += c;
        }
        else v2 += c;
    }

    int val;
    if (v1.size()) val = v1.size() - 1;
    else {
        for (int i = 0; i < v2.size(); i ++) {
            if (v2[i] != '0') {
                val = -i - 1;
                break;
            }
        }
    }

    s = v1 + v2;
    int l = 0, r = s.size() - 1;

    while (s[l] == '0') l ++;
    while (s[r] == '0') r --;

    cout << s[l];
    if (l < r) {
        cout << '.';
        for (int i = l + 1; i <= r; i ++)
            cout << s[i];
    }

    if (val) cout << 'E' << val;

    return 0;
}