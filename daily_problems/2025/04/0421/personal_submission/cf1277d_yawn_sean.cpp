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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

    while (t --) {
        int n;
        cin >> n;

        vector<string> strs(n);
        for (auto &s: strs) cin >> s;

        set<string> st(strs.begin(), strs.end());

        vector<int> w00, w01, w10, w11;
        for (int i = 0; i < n; i ++) {
            if (strs[i][0] == '0') {
                if (strs[i].back() == '0') w00.emplace_back(i);
                else w01.emplace_back(i);
            }
            else {
                if (strs[i].back() == '0') w10.emplace_back(i);
                else w11.emplace_back(i);
            }
        }

        if (w00.size() && w11.size() && w01.empty() && w10.empty()) cout << "-1\n";
        else {
            int c = w01.size() - w10.size();
            vector<int> ans;

            while (c > 1) {
                int idx = w01.back();
                w01.pop_back();

                string s = strs[idx];
                reverse(s.begin(), s.end());

                if (st.find(s) == st.end()) {
                    ans.emplace_back(idx);
                    c -= 2;
                }
            }

            while (c < -1) {
                int idx = w10.back();
                w10.pop_back();

                string s = strs[idx];
                reverse(s.begin(), s.end());

                if (st.find(s) == st.end()) {
                    ans.emplace_back(idx);
                    c += 2;
                }
            }

            cout << ans.size() << '\n';
            for (auto &x: ans) cout << x + 1 << ' '; cout << '\n';
        }
    }

    return 0;
}