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
#define INF (int)2e18

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
    int n,k; cin >> n >> k;
    VC a(n); For(i,0,n-1) cin >> a[i];

    VC idx(256), sz(256,1);
    iota(all(idx), 0ll);

    For(i,0,n-1){
        while(true){
            int id = idx[a[i]];
            if(id == 0) break;

            int nid = idx[id - 1];
            if(sz[id] + sz[nid] > k) break;

            For(j,id,a[i]) idx[j] = nid;
            sz[nid] += sz[id];
        }
        cout << idx[a[i]] << ' ';
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
