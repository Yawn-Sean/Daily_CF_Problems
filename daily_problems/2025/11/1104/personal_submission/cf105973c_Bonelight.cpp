/*
    Bonelight (=v=)
    20251103 Bonelight's submission for 105973/problem/C
*/

#include <bits/stdc++.h>
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

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)
#define all1(_a) (begin(_a) + 1), end(_a)
#define x first
#define y second 

void solve(){
    int mod = 998244353;
    int M = 1e6 + 10;
    VC ans(M+1);

    VC fc(M+1,1), df(M+1,1);
    For(i,1,M) fc[i] = fc[i-1] * i % mod ;
    
    auto qpow = [&](int x, int y){
        int res = 1; 
        while(y > 0){
            if(y & 1) res = res * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    };

    df[M] = qpow(fc[M], mod - 2);
    Rof(i,M,1) df[i-1] = df[i] * i % mod;

    auto comb = [&](int x, int y){
        return fc[y] * df[x] % mod * df[y - x] % mod;
    };

    For(i,1,M){
        ans[i] = ans[i - 1] ^ 1;
        if(i % 2 == 0) ans[i] ^= comb(i/2, i);
    }

    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        cout << ans[n] << endl;
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
