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

    vector<int> nums(n), cnt(11);
    for (auto &num: nums) cin >> num;

    int ans = 0, mod = 998244353;

    for (auto x: nums) {
        int len = 0;
        while (x) x /= 10, len ++;
        cnt[len] ++;
    }

    for (auto x: nums) {
        long long a = x, b = 0, power = 1;

        for (int i = 1; i < 11; i ++) {
            b = (b + a % 10 * power) % mod;
            a /= 10;
            // x 在前面的贡献
            ans += (a * 10 * power + b) % mod * cnt[i] * 10 % mod;
            if (ans >= mod) ans -= mod;
            // x 在后面的贡献
            ans += (a * 100 * power + b) % mod * cnt[i] % mod;
            if (ans >= mod) ans -= mod;
            power = power * 100 % mod;
        }
    }
    cout << ans << '\n';

    return 0;
}