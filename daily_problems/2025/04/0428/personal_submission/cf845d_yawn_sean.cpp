#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    int t;
    cin >> t;

    int ans = 0, speed, forbidden_overtake;
    vector<int> speed_limit;

    while (t --) {
        int q;
        cin >> q;
        if (q == 1) {
            cin >> speed;
            while (!speed_limit.empty() && speed_limit.back() < speed) {
                ans ++;
                speed_limit.pop_back();
            }
        }
        else if (q == 2) {
            ans += forbidden_overtake;
            forbidden_overtake = 0;
        }
        else if (q == 3) {
            int x;
            cin >> x;
            if (x < speed) ans ++;
            else speed_limit.emplace_back(x);
        }
        else if (q == 4) forbidden_overtake = 0;
        else if (q == 5) speed_limit.clear();
        else forbidden_overtake ++;
    }

    cout << ans;

    return 0;
}