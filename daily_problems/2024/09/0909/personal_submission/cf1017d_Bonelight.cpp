#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    int n,m,q; cin >> n >> m >> q;
    vector<int> val(n), cnt(1 << n);
    for(auto &i:val) cin >> i;
    while(m --){
        string s; cin >> s;
        int o = 0;
        for(auto i:s) o = o * 2 + (i == '1');
        cnt[o] ++;
    }

    vector<int> dp(1 << n);
    for(int i = 1; i < (1 << n); i ++){
        int c = i & -i;
        dp[i] = dp[i - c] + val[n - (64 - __builtin_clzll(c))];
    } 

    int tot = (1 << n) - 1;
    vector<vector<int>> ans(101,vector<int>(1 << n));
    for(int i = 0; i < (1 << n); i ++){  
        // 问 i 的情况, 会有 cnt[j] 个 数值为 dp[tot - (i ^ j)] 的 j 匹配
        for(int j = 0; j < (1 << n); j ++){
            if(dp[tot - (i ^ j)] <= 100){
                ans[dp[tot - (i ^ j)]][i] += cnt[j];
            }
        }
        for(int j = 1; j <= 100; j ++){
            ans[j][i] += ans[j - 1][i];
        }
    }

    while(q --){
        string s; cin >> s;
        int mx; cin >> mx;

        int o = 0;
        for(auto i:s) o = o*2 + (i == '1');
        cout << ans[mx][o] << endl;
    }
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
