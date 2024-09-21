#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define INF 2e14
#define pii pair<int, int>

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> g (n + 1, vector<int>());
    vector<int> du (n + 1);
    while(m --){
        int x,y; cin >> x >> y;
        if(x < y) swap(x,y);
        g[x].push_back(y);
        du[x] ++, du[y] ++;
    }
    vector<int> dp(n + 1,1);
    for(int o = 1; o <= n; o ++){
        for(auto p:g[o]){
            dp[o] = max(dp[o], dp[p] + 1);
        }
    }

    int ans = -INF;
    for(int i = 1; i <= n; i ++){
        ans = max(ans, dp[i] * du[i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
    {
        solve();
    }
}
