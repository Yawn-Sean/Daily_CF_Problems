#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    vector<vector<int>> cur(m);
    for (int i = 0; i < n; i ++)
        cur[nums[i] % m].push_back(i);

    vector<int> stk;
    long long ans = 0;
    for (int i = 0; i < 2 * m; i ++) {
        int x = i % m;
        while (stk.size() && cur[x].size() < n / m) {
            int j = stk.back();
            stk.pop_back();
            int v = (x - nums[j] % m + m) % m;
            ans += v, nums[j] += v;
            cur[x].push_back(j);
        }
        while (cur[x].size() > n / m) {
            int j = cur[x].back();
            cur[x].pop_back();
            stk.push_back(j);
        }
    }
    
    cout << ans << '\n';
    for (auto &x: nums) cout << x << ' ';

    return 0;
}