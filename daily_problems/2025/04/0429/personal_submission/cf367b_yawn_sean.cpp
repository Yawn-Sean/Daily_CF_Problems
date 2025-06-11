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

    int n, m, p;
    cin >> n >> m >> p;

    vector<int> nums1(n), nums2(m);

    for (auto &x: nums1) cin >> x;
    for (auto &x: nums2) cin >> x;

    map<int, int> cnt2;
    for (auto &v: nums2) cnt2[v] ++;

    vector<bool> ans(n, 0);
    int total = 0;

    for (int i = 0; i < p; i ++) {
        if (i + 1ll * (m - 1) * p < n) {
            map<int, int> cnt1;
            int cnt = 0;

            auto add_element = [&] (int x) -> void {
                if (cnt2.find(x) != cnt2.end()) {
                    cnt -= (cnt1[x] == cnt2[x]);
                    cnt1[x] ++;
                    cnt += (cnt1[x] == cnt2[x]);
                }
            };

            auto del_element = [&] (int x) -> void {
                if (cnt2.find(x) != cnt2.end()) {
                    cnt -= (cnt1[x] == cnt2[x]);
                    cnt1[x] --;
                    cnt += (cnt1[x] == cnt2[x]);
                }
            };

            for (int j = 0; j < m; j ++)
                add_element(nums1[i + j * p]);
            
            if (cnt == cnt2.size()) ans[i] = 1, total ++;

            for (int ni = i; ni < n; ni += p) {
                if (ni + 1ll * m * p >= n) break;
                del_element(nums1[ni]);
                add_element(nums1[ni + m * p]);
                if (cnt == cnt2.size()) ans[ni + p] = 1, total ++;
            }
        }
    }

    cout << total << '\n';
    for (int i = 0; i < n; i ++)
        if (ans[i]) cout << i + 1 << ' ';

    return 0;
}