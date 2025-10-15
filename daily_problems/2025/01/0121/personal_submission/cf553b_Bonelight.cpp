/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf_553b
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
    int n,m; cin >> n >> m;
    VC dp(n + 1);
    dp[0] = 1; dp[1] = 1;
    For(i,2,n) dp[i] = dp[i - 1] + dp[i -2];

    VC ans;

    int i = 1;
    while(i <= n){
        if(m > dp[n - i]){
            ans.push_back(i+1);
            ans.push_back(i);
            m -= dp[n - i];
            i += 2;
        }else{
            ans.push_back(i);
            i ++;
        }
    }
    for(auto i:ans) cout << i << ' ';
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
