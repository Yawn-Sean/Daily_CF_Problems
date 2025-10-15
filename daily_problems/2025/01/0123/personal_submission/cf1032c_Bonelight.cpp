/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf1032c
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
// #define endl '\n'
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
// #define INF 2e9
#define INF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)
#define all1(_a) (begin(_a) + 1), end(_a)
#define x first
#define y second 

void solve(){
    int n; cin >> n;
    VC a(n+1); For(i,1,n) cin >> a[i];

    MAT dp(6, VC(n+1));
    For(i,1,5) dp[i][1] = -1;

    For(i,2,n){
        For(x,1,5){
            if(dp[x][i-1] != 0)
                For(y,1,5){ // x 上一个，y 这一个
                    if((a[i] > a[i-1] && y > x)
                        || (a[i] == a[i-1] && y != x)
                        || (a[i] < a[i-1] && y < x)){
                        
                        dp[y][i] = x;
                    }
                }
        }
    }

    For(i,1,5){
        if(dp[i][n] != 0){
            VC ans = {i};
            Rof(j,n,2){
                ans.push_back(dp[ans.back()][j]);
            }
            reverse(all(ans));
            for(auto x:ans) cout << x << ' ';
            return;
        }
    }
    cout << -1 << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1;
    while(T --) solve();
    return 0;
}
