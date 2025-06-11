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
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, r;
    cin >> n >> r;

    int chosen = -1, cur = 1e7;

    for (int val = 1; val <= r; val ++) {
        int a = r, b = val, cnt = 0, mistake = 0;

        while (b) {
            int x = a / b;
            a %= b, swap(a, b);
            cnt += x, mistake += x - 1;
        }

        if (a == 1 && cnt == n && mistake < cur) {
            cur = mistake;
            chosen = val;
        }
    }

    if (cur > n) return cout << "IMPOSSIBLE", 0;

    cout << max(0, cur - 1) << '\n';

    vector<int> ar;

    int a = r, b = chosen;
    while (b) {
        ar.emplace_back(a / b);
        a %= b, swap(a, b);
    }

    ar.back() --;
    ar.emplace_back(1);

    reverse(ar.begin(), ar.end());

    for (int i = 0; i < ar.size(); i ++) {
        while (ar[i] --) {
            cout << "TB"[i & 1];
        }
    }

    return 0;
}