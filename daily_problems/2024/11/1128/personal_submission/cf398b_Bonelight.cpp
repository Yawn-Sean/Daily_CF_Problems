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
#define x first
#define y second

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/

void solve(){
    int n,m; cin >> n >> m;
    int rs = n, cs = n;
    VC row(n+1), col(n + 1);
    while(m --){
        int x, y; cin >> x >> y;
        if(!row[x]) row[x] = 1, rs --;
        if(!col[y]) col[y] = 1, cs --;
    }

    vector<vector<long double>> dp(n + 2, vector<long double>(n + 2));
    for(int i = rs; i >= 0; i --)
    for(int j = cs; j >= 0; j --){
        if(i == rs && j == cs) continue;
        int x = rs - i, y = cs - j;
        dp[i][j] = 1.0 * (n*n + x*y*dp[i + 1][j + 1] 
                    + (n - x)*y * dp[i][j + 1]
                    + x*(n - y) * dp[i + 1][j]) / (n*n - (n - x) * (n - y));
    }
    cout << fixed << setprecision(20) << dp[0][0] << endl;
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
