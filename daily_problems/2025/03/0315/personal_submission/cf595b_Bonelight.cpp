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
    vector<int> a(n / k), b(n / k);
    For(i,0,n/k-1) cin >> a[i];
    For(i,0,n/k-1) cin >> b[i];

    int mod = 1e9 + 7, ans = 1;
    int t = 1;
    For(i,0,k-2) t = t*10;
    auto div = [&](int x, int y){return x >= 0? (x/y) + 1: 0ll;};

    For(i,0,n/k - 1){
        ans = (div(t*10-1,a[i]) - (div(t*(b[i]+1)-1, a[i]) - div(t*b[i]-1, a[i]))) % mod * ans % mod;
    }
    cout << (ans+mod) % mod << endl;
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
