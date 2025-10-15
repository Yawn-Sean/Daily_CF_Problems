/*
    Bonelight (=v=) 
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    ID: cf182e
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

void solve(){
    int mod = 1000000007;
    int n,len; cin >> n >> len;
    vector<array<int,3>> a;

    For(i,1,n){
        int x,y; cin >> x >> y;
        a.push_back({x,y,i});
        if(x != y) a.push_back({y,x,i});
    }

    int sz = a.size();
    MAT dp(len+1, VC(sz));

    For(i,0,len){
        For(j,0,sz-1){
            For(k,0,sz-1){
                auto [x1,y1,z1] = a[j];
                auto [x2,y2,z2] = a[k];
                if(!k && x1 == i) dp[i][j] ++;
                if(z1 == z2) continue; 
                
                if(x1 == y2 && i - x2 >= 0){
                    dp[i][k] = (dp[i][k] + dp[i - x2][j]) % mod;
                }
            }
        }
    }

    int ans = 0;
    For(i,0,sz - 1) ans = (ans + dp[len][i]) % mod;
    cout << ans << endl;
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
