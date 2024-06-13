#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, p;
    cin >> n >> k >> p;

    vector<int> dp(k), mod(k);
    int num, cur = 0;

    for (int i = 0; i < n - 1; i ++) {
        cin >> num;
        num %= p, cur += num;
        if (cur >= p) cur -= p;
        for (int j = k - 1; j > 0; j --) 
            if (dp[j-1] + (cur - mod[j-1] + p) % p > dp[j]) {
                dp[j] = dp[j-1] + (cur - mod[j-1] + p) % p;
                mod[j] = cur;
            }
    }

    cin >> num;
    num %= p, cur += num;
    if (cur >= p) cur -= p;

    cout << dp[k-1] + (cur - mod[k-1] + p) % p << '\n';

    return 0;
}