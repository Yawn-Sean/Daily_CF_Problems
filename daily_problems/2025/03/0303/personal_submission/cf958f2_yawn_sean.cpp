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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (auto &x: nums)
        cin >> x;
    
    vector<int> cnt(m + 1);
    for (int i = 1; i <= m; i ++)
        cin >> cnt[i];
    
    int l = 0, r = 0, c = 0, total = 0, ans = n + 5;
    for (int i = 1; i <= m; i ++) {
        total += cnt[i];
        if (!cnt[i]) c ++;
    }

    while (l < n) {
        while (r < n && c < m) {
            cnt[nums[r]] --;
            c += (cnt[nums[r]] == 0);
            r ++;
        }

        if (c < m) break;
        ans = min(ans, r - l);

        c -= (cnt[nums[l]] == 0);
        cnt[nums[l]] ++;
        l ++;
    }

    cout << (ans <= n ? ans - total : -1);

    return 0;
}