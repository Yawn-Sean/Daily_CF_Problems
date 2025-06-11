#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums(m);
    for (auto &v: nums) cin >> v;

    long long orig = 0;
    vector<long long> cur(n + 1);
    vector<vector<int>> tmp(n + 1);

    for (int i = 1; i < m; i ++) {
        int v = abs(nums[i] - nums[i-1]);
        orig += v;
        
        if (nums[i] != nums[i-1]) {
            cur[nums[i]] += v;
            cur[nums[i-1]] += v;
            tmp[nums[i]].emplace_back(nums[i-1]);
            tmp[nums[i-1]].emplace_back(nums[i]);
        }
    }

    long long res = 0;

    for (int i = 1; i <= n; i ++) {
        if (tmp[i].size()) {
            sort(tmp[i].begin(), tmp[i].end());
            int x = tmp[i][tmp[i].size() / 2];

            long long cur_res = 0;
            for (auto &val: tmp[i]) cur_res += abs(val - x);

            res = max(res, cur[i] - cur_res);
        }
    }
    cout << orig - res;

    return 0;
}