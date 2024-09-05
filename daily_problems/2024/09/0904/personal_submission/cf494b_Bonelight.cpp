#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
   string s1,s2; cin >> s1 >> s2;
   int n = s1.size(), m = s2.size();
   s1 = " " + s1, s2 = " " + s2;

    const int sed = 13331;
    const int mo = 1e9 + 7;
    vector<uint> ha(n + 2),len(n + 2);
    len[0] = 1;
    for(int i = 1; i <= n; i ++){
        ha[i] = ha[i - 1] * sed + s1[i] - 'a'; 
        len[i] = len[i - 1] * sed;
    }

    uint s2_ha = 0;
    for(int i = 1; i <= m; i ++){
        s2_ha = s2_ha * sed + s2[i] - 'a';
    }

    vector<int> ok(n + 1);
    for(int i = m; i <= n; i ++){
        uint now = ha[i] - ha[i - m] * len[m];
        if(now == s2_ha) ok[i] = 1;
    }
    
    vector<int> dp(n + 1), sum1(n + 1), sum2(n + 1);
    for(int i = 1; i <= n; i ++){
        if(!ok[i]) dp[i] = dp[i - 1];
        else dp[i] = (sum2[i - m] + (i - m + 1)) % mo;

        sum1[i] = (sum1[i - 1] + dp[i]) % mo;
        sum2[i] = (sum2[i - 1] + sum1[i]) % mo;
    }
    cout << sum1[n] << endl;
}   

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
