#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> ans(n);
    for (int i = 1, j = 0; i < n; i ++) {
        while (j && s[i] != s[j]) j = ans[j-1];
        if (s[i] == s[j]) j ++;
        ans[i] = j;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), k = s2.size();
    vector<int> p = kmp(s2 + "$" + s1), prev(n, -1);

    for (int i = 0; i < n; i ++) {
        if (p[i+k+1] == k) prev[i] = i;
        else if (i) prev[i] = prev[i-1];
    }

    int mod = 1e9 + 7;
    vector<int> dp(n, 0), dp_acc(n, 0), dp_pref(n, 0);

    for (int i = 0; i < n; i ++) {
        if (prev[i] != -1) dp[i] = prev[i] - k + 2;
        if (prev[i] >= k) {
            dp[i] += dp_pref[prev[i] - k];
            if (dp[i] >= mod) dp[i] -= mod;
        }
        if (i) dp_acc[i] = dp_acc[i-1], dp_pref[i] = dp_pref[i-1];
        dp_acc[i] += dp[i];
        if (dp_acc[i] >= mod) dp_acc[i] -= mod;
        dp_pref[i] += dp_acc[i];
        if (dp_pref[i] >= mod) dp_pref[i] -= mod;
    }

    cout << dp_acc[n-1];

    return 0;
}