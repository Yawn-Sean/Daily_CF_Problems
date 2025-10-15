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

    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    vector<int> v1 = {0}, v2 = {0};
    bool flg = true;

    for (auto &c: s) {
        if (c == '.') flg = false;
        else {
            if (flg) v1.emplace_back(c - '0');
            else v2.emplace_back(c - '0');
        }
    }

    int k1 = v1.size(), k2 = v2.size();

    for (int i = 0; i < k2; i ++) {
        if (v2[i] >= 5) {
            while (v2.size() > i) v2.pop_back();
            v2.back() ++, t --;
            break;
        }
    }

    while (t && v2.back() >= 5) {
        t --;
        v2.pop_back();
        v2.back() ++;
    }

    v1.back() += v2[0];
    v2[0] = 0;

    while (!v2.empty() && !v2.back())
        v2.pop_back();
    
    for (int i = k1 - 1; i > 0; i --) {
        if (v1[i] == 10) {
            v1[i] = 0;
            v1[i - 1] ++;
        }
    }

    for (int i = 0; i < k1; i ++)
        if (i || v1[i])
            cout << v1[i];

    if (v2.size()) cout << '.';

    for (int i = 1; i < v2.size(); i ++)
        cout << v2[i];

    return 0;
}