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
    
    long long ans = 1ll * n * n;

    auto solve = [&] () -> void {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int r = 0;

        for (int l = 0; l < n; l ++) {
            while (r < l && !pq.empty() && pq.top() == tmp[r])
                pq.pop(), r ++;
            
            while (r >= l && r < n && nums[r] == tmp[r])
                r ++;
            
            ans = min(ans, 1ll * l * l + 1ll * (n - r) * (n - r));
            if (r <= l) pq.push(nums[l]);
        }
    };

    solve();

    for (auto &x: nums) x = -x;
    reverse(nums.begin(), nums.end());
    solve();

    cout << ans;

    return 0;
}