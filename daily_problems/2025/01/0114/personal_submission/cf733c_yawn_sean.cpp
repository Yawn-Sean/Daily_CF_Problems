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

    int k;
    cin >> k;

    vector<pair<int, int>> ans;
    int pt = 0, start_idx = 1;

    while (k --) {
        int v;
        cin >> v;

        int l, r, cur = 0;
        l = pt;
        while (pt < n && cur < v) {
            cur += nums[pt];
            pt ++;
        }
        r = pt;

        if (cur != v) return cout << "NO", 0;

        if (r - l > 1) {
            int ma = *max_element(nums.begin() + l, nums.begin() + r);
            bool flg = false;

            for (int i = l; i < r; i ++) {
                if (nums[i] == ma) {
                    if (i > l && nums[i] > nums[i - 1]) {
                        flg = true;

                        for (int j = i - 1; j >= l; j --)
                            ans.emplace_back(start_idx + j + 1 - l, 0);
                        
                        for (int j = i + 1; j < r; j ++)
                            ans.emplace_back(start_idx, 1);
                        
                        break;
                    }
                    else if (i + 1 < r && nums[i] > nums[i + 1]) {
                        flg = true;

                        for (int j = i + 1; j < r; j ++)
                            ans.emplace_back(start_idx + i - l, 1);
                        
                        for (int j = i - 1; j >= l; j --)
                            ans.emplace_back(start_idx + j + 1 - l, 0);
                        
                        break;
                    }
                }
            }

            if (!flg) return cout << "NO", 0;
        }

        start_idx ++;
    }

    if (pt < n) return cout << "NO", 0;

    cout << "YES\n";

    for (auto &[x, y]: ans)
        cout << x << ' ' << (y ? 'R' : 'L') << '\n';

    return 0;
}