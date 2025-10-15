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
    
    map<int, int> mp;
    for (auto &x: nums) mp[x] ++;

    int ans = mp[0];

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i == j || (nums[i] == 0 && nums[j] == 0)) continue;

            vector<int> cur = {nums[i], nums[j]};
            mp[cur[0]] --, mp[cur[1]] --;

            while (true) {
                int val = cur[cur.size() - 1] + cur[cur.size() - 2];
                if (mp.find(val) == mp.end() || mp[val] == 0) break;
                cur.emplace_back(val);
                mp[val] --;
            }
            ans = max(ans, (int)cur.size());

            for (auto &x: cur) mp[x] ++;
        }
    }
    cout << ans;

    return 0;
}