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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums)
        cin >> x;
    
    bool flg = true;
    for (int i = 1; i < n; i ++) {
        if (nums[i] < nums[i - 1]) {
            flg = false;
        }
    }

    if (flg) cout << 0;
    else {
        auto check = [&] (int x) -> bool {
            while (x) {
                if (x % 10 != 4 && x % 10 != 7)
                    return false;
                x /= 10;
            }
            return true;
        };

        int idx = -1;
        for (int i = 0; i < n; i ++) {
            if (check(nums[i])) {
                idx = i;
            }
        }

        if (idx == -1) cout << -1;
        else {
            vector<int> order(n), pos(n), cur(n);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] < nums[j];});
            iota(pos.begin(), pos.end(), 0);
            iota(cur.begin(), cur.end(), 0);

            vector<pair<int, int>> ops;

            auto swap_element = [&] (int i, int j) -> void {
                if (i == j) return ;
                i = pos[i], j = pos[j];
                ops.emplace_back(i, j);

                swap(pos[cur[i]], pos[cur[j]]);
                swap(cur[i], cur[j]);
            };

            for (int i = 0; i < n; i ++)
                swap_element(cur[i], idx), swap_element(order[i], idx);
            
            cout << ops.size() << '\n';
            for (auto &[x, y]: ops)
                cout << x + 1 << ' ' << y + 1 << '\n';
        }
    }

    return 0;
}