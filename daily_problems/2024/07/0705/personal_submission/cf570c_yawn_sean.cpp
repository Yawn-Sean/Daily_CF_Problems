#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<int> nums(n + 2);

    for (int i = 1; i <= n; i ++) 
        nums[i] = s[i-1] == '.';
    
    int ans = 0, cur = 0;
    for (auto &x: nums) {
        if (x) cur ++;
        else cur = 0;
        if (cur > 1) ans ++;
    }

    while (q --) {
        int i;
        char c;
        cin >> i >> c;
        int flg = (c == '.');
        if (flg != nums[i]) {
            if (flg) {
                ans ++;
                ans += nums[i-1] & nums[i+1];
                ans -= (nums[i-1] ^ 1) & (nums[i+1] ^ 1);
            }
            else {
                ans --;
                ans -= nums[i-1] & nums[i+1];
                ans += (nums[i-1] ^ 1) & (nums[i+1] ^ 1);
            }
        }
        nums[i] = flg;
        cout << ans << '\n';
    }

    return 0;
}