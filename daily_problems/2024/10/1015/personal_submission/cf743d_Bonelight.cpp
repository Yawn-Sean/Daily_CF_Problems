/*
    Bonelight * v *
    20241015：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long 
#define INF 5e14
#define pii pair<int,int>

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> g(n + 1, vector<int>());
    for(int i = 1; i <= n; i ++){cin >> a[i];}

    for(int i = 1; i <= n - 1; i ++){
        int x, y; cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
    } 

    vector<int> dp(n + 1,-INF), d(n + 1), sum(n + 1);
    vector<vector<int>> hp(n + 1, vector<int>());

    function<void(int,int)> dfs = [&](int o, int fa){
        sum[o] = a[o]; 
        d[o] = d[fa] + 1; 
        hp[d[o]].push_back(o);
        
        for(auto &p:g[o]) if(p != fa){
            dfs(p,o);
            dp[o] = max(dp[o], dp[p]);
            sum[o] += sum[p];
        }
        dp[o] = max(dp[o], sum[o]);
    }; dfs(1,0);

    int ans = -INF;
    for(int i = 1; i <= n; i ++) if(hp[i].size() >= 2){
        int mx1 = -INF, mx2 = -INF;
        for(auto p:hp[i]){
            if(dp[p] > mx1) mx2 = mx1, mx1 = dp[p];
            else if(dp[p] > mx2) mx2 = dp[p];
        }
        ans = max(ans, mx1 + mx2);
    }
    if(ans == -INF) cout << "Impossible" << endl;
    else cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
