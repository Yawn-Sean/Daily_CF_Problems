/*
    Bonelight (=v=)
    20250110: 写屑代码一个笨蛋
    == UnderLight == 
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

    VC diff(n + 1), ans(n + 1, 1e9);
    vector<tuple<int,int,int,int>> ops(m + 1);
    
    For(i,1,m){
        auto &[op, l, r, v] = ops[i];
        cin >> op >> l >> r >> v;
        
        if(op == 1) For(j,l,r) diff[j] += v;
        else{ 
            For(j,l,r) ans[j] = min(ans[j], v - diff[j]);
        } 
    }

    VC tmp = ans;
    For(i,1,m){
        auto [op,l,r,v] = ops[i];
        if(op == 1){ For(j,l,r) tmp[j] += v;}
        else {
            int t = -(1e9);
            For(j,l,r) {
                t = max(t, tmp[j]);
            }
            if(v != t) return void(cout << "NO" << endl);
        } 
    }
    cout << "YES" << endl;
    For(i,1,n) cout << ans[i] << " ";
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
