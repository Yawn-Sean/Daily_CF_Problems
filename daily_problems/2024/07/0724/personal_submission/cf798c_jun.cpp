/*
 * @Descripttion: 
 * @Author: Hejun
 * @version: 
 * @Date: 2024-07-24 16:53:36
 * @LastEditors: Hejun
 * @LastEditTime: 2024-07-24 18:22:58
 */
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    int g = 0;
    for (auto &num: nums)
      cin >> num, g = __gcd(g, num);

    cout << "YES\n";
    if (g > 1) 
        cout << 0;
    else {
        int ans = 0, cnt = 0;
        for (auto &num: nums) {
            if (num & 1) 
                cnt ++;
            else
                ans += cnt / 2 + cnt % 2 * 2, cnt = 0;
        }
        ans += cnt / 2 + cnt % 2 * 2;
        cout << ans;
    }

    return 0;

}