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
#define INF 2e9
#define INFF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)

void solve(){
    int n; cin >> n; 
    VC a(n+1); For(i,1,n) cin >> a[i];
    sort(all(a));
    VC pre(n+1), sub(n+2);
    For(i,1,n) pre[i] = pre[i-1] + a[i];
    Rof(i,n,1) sub[i] = sub[i+1] + a[i];

    int son = 0;
    // For(i,1,n) cout << pre[i] << ' '; /**/ cout << endl;
    // For(i,1,n) cout << sub[i] << ' '; /**/ cout << endl;
    For(i,1,n) son += a[i] + (i * a[i] - pre[i]) + (sub[i + 1] - (n-i) * a[i]); 
    cout << son / __gcd(son,n) << " " << n / __gcd(son,n);
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1; //cin >> T;
    while(T --) solve();
    return 0;
}
