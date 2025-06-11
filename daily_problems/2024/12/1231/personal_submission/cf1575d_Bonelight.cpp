/*
    Bonelight (=v=)
    20241211: New Light
    == Under Fire == 
    #pragma GCC optimize(2)
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)

void solve(){
    string s; cin >> s; 
    int n = s.size();
    bool hasX = 0; For(i,0,n-1) if(s[i] == 'X') hasX = true;
    auto calc = [&](int x, int y){return (10*x + y) % 25;};
    int ans = 0;
    if(n == 1) return void(cout << (s == "0" || s == "X" || s == "_")? 1:0 << endl);
    For(x,0,(hasX? 9:0)){
        VC dp(25), ndp(25);
        dp[0] = 1;
        For(i,0,n-1){
            if(s[i] == '_'){
                For(v,0,9){
                    if(i==0 && v==0) continue;
                    For(j,0,24){
                        ndp[calc(j,v)] += dp[j];
                    }
                }
            } else {
                int v = s[i] == 'X'? x:(s[i]-'0');
                if(!(i==0 && v==0)){
                    For(j,0,24) ndp[calc(j,v)] += dp[j];
                }
            }

            For(j,0,24){
                dp[j] = ndp[j];
                ndp[j] = 0;
            }
        }
        // cout << "run" << endl;
        ans += dp[0];
    }
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
