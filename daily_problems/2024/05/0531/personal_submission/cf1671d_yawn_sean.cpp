#include <bits/stdc++.h>
using namespace std;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while (q --) { 
        int n, x;
        cin >> n >> x;
        vector<int> nums(n);

        for (int i = 0; i < n; i ++)
            cin >> nums[i];
        
        long long ans = 0;

        for (int i = 1; i < n; i ++)
            ans += abs(nums[i] - nums[i-1]);
        
        int add = min(nums[0], nums[n-1]) - 1;
        add = min(add, 2 * *min_element(nums.begin(), nums.end()) - 2);

        ans += add;

        add = x - max(nums[0], nums[n-1]);
        add = min(add, 2 * x - 2 * *max_element(nums.begin(), nums.end()));
        
        ans += max(0, add);
        cout << ans << '\n';
    }

    return 0;
}