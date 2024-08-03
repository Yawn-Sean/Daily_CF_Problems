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

    int n, k;
    cin >> n >> k;
    vector<int> nums(n), next_pos(n), pos(n, n);

    for (int i = 0; i < n; i ++)
        cin >> nums[i], nums[i] --;

    for (int i = n - 1; i >= 0; i --)
        next_pos[i] = pos[nums[i]], pos[nums[i]] = i;
    
    int ans = 0;
    set<int> st;
    for (int i = 0; i < n; i ++) {
        if (!st.empty() && *st.begin() == i)
            st.erase(i), st.emplace(next_pos[i]);
        else {
            if (st.size() == k)
                st.erase(*(--st.end()));
            ans ++, st.emplace(next_pos[i]);
        }
    }
    cout << ans << '\n';

    return 0;
}