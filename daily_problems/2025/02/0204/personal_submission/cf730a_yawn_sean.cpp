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
    for (auto &v: nums)
        cin >> v;
    
    vector<string> ops;

    auto op = [&] (vector<int> idxs) -> void {
        for (auto &i: idxs) nums[i] = max(nums[i] - 1, 0);
        string res(n, '0');
        for (auto &i: idxs) res[i] = '1';
        ops.emplace_back(res);
    };

    while (*min_element(nums.begin(), nums.end()) != *max_element(nums.begin(), nums.end())) {
        int v = *max_element(nums.begin(), nums.end());
        vector<int> idxs;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == v) {
                idxs.emplace_back(i);
            }
        }
        int c = idxs.size();

        if (c > 1) {
            if (c % 2 == 0) {
                for (int i = 0; i < c; i += 2) {
                    op({idxs[i], idxs[i + 1]});
                }
            }
            else {
                op({idxs[0], idxs[1], idxs[2]});
                for (int i = 3; i < c; i += 2) {
                    op({idxs[i], idxs[i + 1]});
                }
            }
        }
        else {
            int idx = -1;
            for (int i = 0; i < n; i ++) {
                if (nums[i] != v && (idx == -1 || nums[i] > nums[idx])) {
                    idx = i;
                }
            }
            op({idx, idxs[0]});
        }
    }

    cout << nums[0] << '\n';
    cout << ops.size() << '\n';
    for (auto &x: ops) cout << x << '\n';

    return 0;
}