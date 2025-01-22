/*
    Bonelight * v *
    20241101：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>
#define tiii tuple<int,int,int>

void solve(){
    int n,m,k; cin >> n >> m >> k;
    string s1,s2; cin >> s1 >> s2;
    s1 = " " + s1, s2 = " " + s2;
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int _ = 1; _ <= k; _ ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(s1[i] == s2[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }

        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
            }
        }
    }
    cout << dp[n][m] << endl;
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1; 
    while(T --){
        solve();
    }
}
