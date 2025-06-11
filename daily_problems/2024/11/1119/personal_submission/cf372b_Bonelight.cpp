/*
    Bonelight =^x^=
    20241117: 单枪匹马，无畏粉身碎骨
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>  
#define INF 2e18
#define VC vector<int>
#define MAT vector<VC>
/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    int n,m,q; cin >> n >> m >> q;
    MAT pre(n+1, VC(m + 1));
    for(int i = 1; i <= n; i ++){
        string s; cin >> s; s = " " + s;
        for(int j = 1; j <= m; j ++){
            pre[i][j] = s[j] - '0'; 
        }
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    auto check = [&](int x1, int y1, int x2, int y2){
        return (pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1 - 1] + pre[x1-1][y1-1] == 0);
    };

    vector<vector<MAT>> dp(n+2, vector<MAT>(m+2, MAT(n+2, VC(m+2))));
    for(int x1 = 1; x1 <= n; x1 ++)
    for(int y1 = 1; y1 <= m; y1 ++)
    for(int x2 = x1; x2 <= n; x2 ++)
    for(int y2 = y1; y2 <= m; y2 ++){
        if(check(x1,y1,x2,y2))
            dp[x1][y1][x2][y2]++;
    }

    for(int x1 = n; x1 >= 1; x1 --)
    for(int y1 = m; y1 >= 1; y1 --)
    for(int x2 = 1; x2 <= n; x2 ++)
    for(int y2 = 1; y2 <= m; y2 ++){
        dp[x1][y1][x2][y2] += dp[x1 + 1][y1][x2][y2];
    }   
    for(int x1 = n; x1 >= 1; x1 --)
    for(int y1 = m; y1 >= 1; y1 --)
    for(int x2 = 1; x2 <= n; x2 ++)
    for(int y2 = 1; y2 <= m; y2 ++){
        dp[x1][y1][x2][y2] += dp[x1][y1 + 1][x2][y2];
    }   
    for(int x1 = n; x1 >= 1; x1 --)
    for(int y1 = m; y1 >= 1; y1 --)
    for(int x2 = 1; x2 <= n; x2 ++)
    for(int y2 = 1; y2 <= m; y2 ++){
        dp[x1][y1][x2][y2] += dp[x1][y1][x2 - 1][y2];
    }   
    for(int x1 = n; x1 >= 1; x1 --)
    for(int y1 = m; y1 >= 1; y1 --)
    for(int x2 = 1; x2 <= n; x2 ++)
    for(int y2 = 1; y2 <= m; y2 ++){
        dp[x1][y1][x2][y2] += dp[x1][y1][x2][y2 - 1];
    }   
        
    while(q --){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x1][y1][x2][y2] << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; //cin >> T;
    while(T --){
        solve();
    } 
}
