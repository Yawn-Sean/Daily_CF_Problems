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

    int t;
    cin >> t;

    while (t --) {
        int n, l;
        vector<int> nums(3);
        cin >> n >> nums[0] >> nums[1] >> nums[2] >> l;

        vector<int> vals(n + 1);
        for (auto &x: vals) cin >> x;

        set<int> st(vals.begin(), vals.end());

        int ans = 3;
        vector<int> used(3, 0);

        auto search1 = [&] (int x) -> int {
            for (auto &v: vals) {
                if (v - x >= 0 && st.find(v - x) != st.end()) {
                    return 0;
                }
            }
            return 1;
        };

        auto search2 = [&] (int x, int y) -> int {
            int d;
            d = x + y;
            for (auto &v: vals) {
                if (v - d >= 0 && st.find(v - d) != st.end()) {
                    return 1;
                }
            }
            if (x > y) swap(x, y);
            d = y - x;
            for (auto &v: vals) {
                if (v - d >= 0 && st.find(v - d) != st.end() && (v - y >= 0 || v + x <= l)) {
                    return 1;
                }
            }
            return 2;
        };

        auto search3 = [&] (auto &self, vector<int> &tmp, int idx, int cnt) -> void {
            if (idx == 3) {
                ans = min(ans, cnt);
                return ;
            }
            auto v = tmp;
            for (auto &cur: v) {
                for (int i = 0; i < 3; i ++) {
                    if (!used[i]) {
                        used[i] = 1;
                        if (cur + nums[i] <= l) {
                            tmp.emplace_back(cur + nums[i]);
                            self(self, tmp, idx + 1, cnt + (st.find(cur + nums[i]) == st.end()));
                            tmp.pop_back();
                        }
                        if (cur - nums[i] >= 0) {
                            tmp.emplace_back(cur - nums[i]);
                            self(self, tmp, idx + 1, cnt + (st.find(cur - nums[i]) == st.end()));
                            tmp.pop_back();
                        }
                        used[i] = 0;
                    }
                }
            }
        };

        ans = min(ans, search1(nums[0]) + search1(nums[1]) + search1(nums[2]));
        ans = min(ans, search1(nums[0]) + search2(nums[1], nums[2]));
        ans = min(ans, search1(nums[1]) + search2(nums[0], nums[2]));
        ans = min(ans, search1(nums[2]) + search2(nums[0], nums[1]));

        vector<int> tmp;
        for (auto &v: vals) {
            tmp.emplace_back(v);
            search3(search3, tmp, 0, 0);
            tmp.pop_back();
        }

        cout << ans << '\n';
    }

    return 0;
}