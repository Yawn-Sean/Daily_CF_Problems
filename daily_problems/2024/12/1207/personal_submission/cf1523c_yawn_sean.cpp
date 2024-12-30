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

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;
        vector<int> stk;
        while (n --) {
            int x;
            cin >> x;
            if (x == 1) stk.emplace_back(1);
            else {
                while (stk.back() != x - 1)
                    stk.pop_back();
                stk.back() ++;
            }
            int k = stk.size();
            cout << stk[0];
            for (int i = 1; i < k; i ++)
                cout << '.' << stk[i];
            cout << '\n';
        }
    }

    return 0;
}