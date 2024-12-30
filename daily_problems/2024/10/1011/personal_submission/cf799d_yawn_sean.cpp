#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;
    
    sort(nums.rbegin(), nums.rend());

    n = min(n, 34);
    int inf = 100;

    auto f = [&] (int x, int y) -> int {
        map<pair<int, int>, int> mp;
        mp[{x, y}] = 0;

        for (int i = 0; i < n; i ++) {
            vector<pair<int, int>> pairs;
            for (auto &[k, v]: mp) pairs.emplace_back(k);

            for (auto &[x, y]: pairs) {
                int nx = (x + nums[i] - 1) / nums[i], ny = (y + nums[i] - 1) /  nums[i];

                if (mp.find({nx, y}) == mp.end())
                    mp[{nx, y}] = mp[{x, y}] + 1;
                if (mp.find({x, ny}) == mp.end())
                    mp[{x, ny}] = mp[{x, y}] + 1;
            }
        }

        return mp.find({1, 1}) == mp.end() ? inf : mp[{1, 1}];
    };

    int ans = min(f((a + w - 1) / w, (b + h - 1) / h), f((a + h - 1) / h, (b + w - 1) / w));
    cout << (ans < inf ? ans : -1);

    return 0;
}