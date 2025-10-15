/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf180e_Bonelight.cpp
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
    int n,m,del; cin >> n >> m >> del;
    VC a(n+1); 
    map<int, VC> mp;
    For(i,1,n) {
        int x; cin >> x;
        mp[x].push_back(i);
    } 

    auto check = [&](int x){
        int ok = 0;
        for(auto [_,v]:mp){
            int sz = v.size();
            for(int i = 0; i + x - 1 < sz; i ++){
                if(v[i + x - 1] - v[i] + 1 - x <= del) {ok = 1; break;}
            }
        }
        return ok;
    };

    int l = 0, r = n+1; 
    while(l + 1 < r){
        int mid = l + r >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
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
