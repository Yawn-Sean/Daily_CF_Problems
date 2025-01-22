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

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    int k;
    cin >> k;
    
    vector<int> notes(n, 0);
    while (k --) {
        int u;
        cin >> u;
        notes[u - 1] = 1;
    }

    vector<int> stk;
    for (int i = n - 1; i >= 0; i --) {
        if (notes[i]) stk.emplace_back(i);
        else if (!stk.empty() && nums[stk.back()] == nums[i]) {
            int u = stk.back();
            stk.pop_back();
            nums[u] = -nums[u];
        }
        else stk.emplace_back(i);
    }

    if (stk.empty()) {
        cout << "YES\n";
        for (auto &v: nums) cout << v << ' ';
    }
    else cout << "NO";

    return 0;
}