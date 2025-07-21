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

    int n;
    cin >> n;

    vector<int> nums(n * 2);
    for (auto &v: nums) cin >> v;

    vector<pair<int, int>> intervals;

    int l = 0;
    while (l < n * 2) {
        int r = l;
        while (r + 1 < n * 2 && nums[r + 1] < nums[l])
            r ++;
        intervals.emplace_back(l, r);
        l = r + 1;
    }

    vector<int> dp(n + 1, -2);
    dp[0] = -1;

    for (int i = 0; i < intervals.size(); i ++) {
        int x = intervals[i].second - intervals[i].first + 1;
        for (int y = n; y >= x; y --) {
            if (dp[y - x] != -2 && dp[y] == -2) {
                dp[y] = i;
            }
        }
    }

    if (dp[n] == -2) return cout << -1, 0;

    vector<int> choice(2 * n, 0);
    int cur = n;

    while (cur) {
        int idx = dp[cur];
        auto [l, r] = intervals[idx];
        
        for (int i = l; i <= r; i ++)
            choice[i] = 1;
        
        cur -= r - l + 1;
    }

    for (int i = 0; i < 2 * n; i ++)
        if (choice[i]) cout << nums[i] << ' ';
    cout << '\n';
    
    for (int i = 0; i < 2 * n; i ++)
        if (!choice[i]) cout << nums[i] << ' ';
    cout << '\n';

    return 0;
}