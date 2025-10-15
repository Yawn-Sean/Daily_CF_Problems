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
    int n,q; cin >> n >> q;
    int ans = 0, p = 0;
    VC stk,cnt(n+1), last(n+1);
    while(q --){
        int op,v; cin >> op >> v;
        if(op == 1){
            ans ++, cnt[v] ++;
            stk.push_back(v);
        } else if(op == 2) {
           ans -= cnt[v]; cnt[v] = 0;
           last[v] = stk.size(); 
        } else {
            while(p < v){
                if(p >= last[stk[p]]) {ans --, cnt[stk[p]] --;}
                p ++;
            }
        }
        cout << ans << endl;
    }
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
