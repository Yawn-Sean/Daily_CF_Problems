#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14

void solve()
{
    int n,m; string s; cin >> n >> s >> m;
    s = " " + s;

    vector<int> la(n + 2), lb(n + 2), pre(n + 2);
    for(int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] + (s[i] == '?');
    }
    for(int i = n; i >= 1; i --){
        la[i] = s[i] != 'b'? lb[i + 1] + 1: 0;
        lb[i] = s[i] != 'a'? la[i + 1] + 1: 0;
    }
    vector<int> dp(n + 2), cg(n + 2);
    for(int i = 1; i <= n; i ++){
        if(dp[i] > dp[i + 1] || (dp[i] == dp[i + 1] && cg[i] < cg[i + 1])){
            dp[i + 1] = dp[i];
            cg[i + 1] = cg[i];
        }
        if(la[i] >= m){
            int nval = dp[i] + 1,  ncg = cg[i] + pre[i + m - 1] - pre[i - 1];
            if(nval > dp[i + m] || (nval == dp[i + m] && ncg < cg[i + m])){
                dp[i + m] = nval;
                cg[i + m] = ncg;
            }
        }
    }
    cout << cg[n + 1] << endl;
}  

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
