/*
    Bonelight (=v=)
    20251120 https://codeforces.com/gym/104536/problem/E
*/

#include <bits/stdc++.h>
// #include <atcoder/segtree>
// using namespace atcoder;
using namespace std;

#define i64 long long
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
// #define INF 2e9
#define INF (int)2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define ForR(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define RofR(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define For(_i,_l,_r) for(int _i = _l; _i < _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i > _l; _i --)
#define all(_a) begin(_a), end(_a)
#define all1(_a) (begin(_a) + 1), end(_a)
#define x first
#define y second 

void solve(){
    int n; cin >> n; 
    VC a(n),b(n); 
    For(i,0,n) cin >> a[i];
    For(i,0,n) cin >> b[i];
    
    VC c;
    For(i,0,n){
        if(a[i] >= b[i]) c.emplace_back(a[i]), c.emplace_back(b[i]); 
        else c.emplace_back(b[i]), c.emplace_back(a[i]);
    }

    VC ans;
    for(auto i:c){
        int p = lower_bound(all(ans),i) - ans.begin();
        
        if(p == ans.size()) ans.push_back(i);
        else ans[p] = i;
    }

    cout << ans.size() << endl;

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
