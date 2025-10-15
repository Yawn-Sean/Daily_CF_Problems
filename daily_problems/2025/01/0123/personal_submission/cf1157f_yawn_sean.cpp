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

    vector<int> cnt(200002, 0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v, cnt[v] ++;
    
    int ans = 0, start = -1;

    int pt = 0;
    while (pt < cnt.size()) {
        if (cnt[pt] > 1) {
            int lpt = pt, cur = 0;
            while (cnt[pt] > 1) {
                cur += cnt[pt];
                pt ++;
            }
            if (cnt[lpt - 1]) cur ++;
            if (cnt[pt]) cur ++;
            if (cur > ans) {
                ans = cur;
                start = lpt;
            }
        }
        else pt ++;
    }

    if (ans >= 2) {
        int l = start;
        while (cnt[start] > 1)
            start ++;
        int r = start;

        vector<int> ans;
        if (cnt[l - 1]) ans.emplace_back(l - 1);
        
        for (int i = l; i < r; i ++)
            ans.emplace_back(i);
        
        if (cnt[r]) ans.emplace_back(r);

        for (int i = r - 1; i >= l; i --) {
            for (int j = 0; j < cnt[i] - 1; j ++) {
                ans.emplace_back(i);
            }
        }

        cout << ans.size() << '\n';
        for (auto &v: ans)
            cout << v << ' ';
    }
    else {
        for (int i = 0; i <= 200000; i ++) {
            if (cnt[i] && cnt[i + 1]) {
                cout << 2 << '\n';
                cout << i << ' ' << i + 1;
                return 0;
            }
        }
        cout << 1 << '\n';
        cout << nums[0];
    }

    return 0;
}