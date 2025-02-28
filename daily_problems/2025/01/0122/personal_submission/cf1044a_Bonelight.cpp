/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf1044a_Bonelight.cpp
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
    int n,m; cin >> n >> m;
    VC a(n+1), b;
    For(i,1,n) cin >> a[i];
    For(i,1,m){
        int x1,x2,y; cin >> x1 >> x2 >> y;
        if(x1 == 1) b.push_back(x2);
    }
    m = b.size();

    sort(all1(a));
    sort(all(b));
    a.push_back(1e9);

    int ans = m, p = 0;
    For(i,0,n){
        while(p < m && a[i+1] > b[p]) p++;
        ans = min(ans, i + m - p);
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
