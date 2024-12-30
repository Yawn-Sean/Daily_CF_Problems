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

    int t;
    cin >> t;

    while (t --) {
        string s;
        cin >> s;

        int n = s.size();

        vector<int> pref_zero(n + 1);
        for (int i = 0; i < n; i ++) 
            if (s[i] == '0') pref_zero[i+1] = pref_zero[i] + 1;
        
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            int cur = 0;
            for (int j = i; j >= 0 && i - j <= 18; j --) {
                if (s[j] == '1') {
                    cur |= 1 << i - j;
                    if (i - j + 1 + pref_zero[j] >= cur) ans ++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}