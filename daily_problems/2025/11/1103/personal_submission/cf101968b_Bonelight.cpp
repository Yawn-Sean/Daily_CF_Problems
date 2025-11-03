/*
    Bonelight (=v=)
    20251103 Bonelight's submission for 101968/problem/B
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

VC fc(5e5 + 5, 1);
int mod = 1e9 + 7;
void solve(){
    int n; cin >> n; n *= 2;
    VC X(n),Y(n);
    For(i,0,n-1) cin >> X[i] >> Y[i];
    
    VC Xc = X, Yc = Y;
    sort(all(Xc));
    sort(all(Yc));

    n /= 2;
    if(Xc[n-1] == Xc[n]) return void(cout << 0 << endl);
    if(Yc[n-1] == Yc[n]) return void(cout << 0 << endl);
    
    n *= 2;
    int x = 0;
    For(i,0,n-1) if(X[i] < Xc[n/2] && Y[i] < Yc[n/2]) x ++;
    cout << fc[x] * fc[n/2 - x] % mod << endl;

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1; cin >> T;
    For(i,1,5e5 + 5 - 1) fc[i] = fc[i-1] * i % mod;
    while(T --) solve();
    return 0;
}
