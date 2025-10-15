#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> nums(n);
        for (auto &v: nums) cin >> v;

        int inf = 2e9;
        vector<int> pref_min(n + 1, inf), suff_min(n + 1, inf);

        for (int i = 0; i < n; i ++)
            pref_min[i + 1] = min(pref_min[i], nums[i] - (nums[i] & y));
        
        for (int i = n - 1; i >= 0; i --)
            suff_min[i] = min(suff_min[i + 1], nums[i] - (nums[i] & y));
        
        long long total = 0, ans = 1e15;
        for (auto &v: nums) total += v;

        for (int i = 0; i < n; i ++) {
            long long res = total - nums[i] + (nums[i] | x);
            int to_delete = min(pref_min[i], suff_min[i + 1]);
            to_delete = min(to_delete, (nums[i] | x) - ((nums[i] | x) & y));
            res -= to_delete;
            ans = min(ans, res);
        }

        cout << ans << '\n';
    }

    return 0;
}