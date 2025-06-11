/*
    Bonelight * V *
    20240928: Want be blue
    No Coding, No Bug 
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14

void solve()
{
    int n,m; cin >> n >> m;
    vector<vector<int>> g(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> g[i][j];
        }
    }

    vector<vector<int>> dp1,dp2,dp3,dp4;
    dp1 = dp2 = dp3 = dp4 = vector<vector<int>>(n + 2, vector<int>(m + 2));
    
    for(int i = 1; i <= n; i ++){ // 左上
        for(int j = 1; j <= m; j ++){
            dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + g[i][j];
        }
    }
    for(int i = n; i >= 1; i --){ // 右下
        for(int j = m; j >= 1; j --){
            dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + g[i][j];
        }
    }
    for(int i = 1; i <= n; i ++){ // 右上
        for(int j = m; j >= 1; j --){
            dp3[i][j] = max(dp3[i - 1][j], dp3[i][j + 1]) + g[i][j];
        }
    }
    for(int i = n; i >= 1; i --){ // 左下
        for(int j = 1; j <= m; j ++){
            dp4[i][j] = max(dp4[i + 1][j], dp4[i][j - 1]) + g[i][j];
        }
    }
    
    int ans = 0;
    for(int i = 2; i <= n - 1; i ++){
        for(int j = 2; j <= m - 1; j ++){
            int t = ans;
            ans = max(ans, dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j + 1] + dp4[i][j - 1]);
            ans = max(ans, dp1[i][j - 1] + dp2[i][j + 1] + dp3[i - 1][j] + dp4[i + 1][j]);
        }
    }
    cout << ans << endl;
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
