/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 总所周知，史官就是写 shi 的嘛 == 
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
    int x1,y1,z1; cin >> x1 >> y1 >> z1;
    int x2,y2,z2; cin >> x2 >> y2 >> z2;

    int a1,a2,a3,a4,a5,a6; cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;         
    
    int ans = 0;
    if(x1 < 0) ans += a5; 
    if(y1 < 0) ans += a1;
    if(z1 < 0) ans += a3;

    if(x1 > x2) ans += a6;
    if(y1 > y2) ans += a2;
    if(z1 > z2) ans += a4;

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
