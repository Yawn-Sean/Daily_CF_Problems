#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std; 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int m = s.size();
    vector<int> last(k, -1);

    for (int i = 0; i < m; i ++)
        last[s[i] - 'a'] = i;
    
    vector<int> order(k);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return last[i] < last[j];});

    vector<int> dp(k, 0);
    int total = 0, mod = 1e9 + 7;

    for (auto &ch: s) {
        int c = ch - 'a';
        int v = total - dp[c] + 1;
        if (v < 0) v += mod;
        dp[c] += v;
        if (dp[c] >= mod) dp[c] -= mod;
        total += v;
        if (total >= mod) total -= mod;
    }

    for (int i = 0; i < n; i ++) {
        int c = order[i % k];
        int v = total - dp[c] + 1;
        if (v < 0) v += mod;
        dp[c] += v;
        if (dp[c] >= mod) dp[c] -= mod;
        total += v;
        if (total >= mod) total -= mod;
    }
    
    total ++;
    if (total == mod) total = 0;
    cout << total;

    return 0;
}