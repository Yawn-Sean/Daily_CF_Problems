/*
    Bonelight (=v=)
    20251027 Bonelight's submission for 106073/problem/F
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
    int mod = 1e9 + 7;
    int n,m; cin >> n >> m;
    VC a(n+1), ans(n + 1);

    auto qpow = [&](int x, int y){
        int res = 1;
        while(y > 0) {
            if(y & 1) res = res * x % mod;
            x = x*x % mod;
            y >>= 1;
        }
        return res;
    };

    int p2 = qpow(2, mod - 2);

    // a[1] = 1; ........ 超时，需要优化数式
    // For(_,1,m){
    //     int x; cin >> x;
    //     For(i,1,n){
    //         ans[i] =  ans[i] + (p2 * x % mod) * a[i] % mod; // ans[i] += p2 * x * a[i]
    //         ans[i] %= mod;
    //     }
    //     For(i,1,n){a[i] = a[i] * p2 % mod;}
    //     a[x] = a[x] + p2; a[x] %= mod;
    // }

    VC nums(m+1);
    For(i,1,m) cin >> nums[i];
    
    int cur = 0;
    Rof(i,m,1) {
        int x = nums[i];
        ans[x] += cur * p2 % mod; ans[x] %= mod;
        cur = (cur + x) * p2 % mod;
    }
    ans[1] = (ans[1] + cur) % mod;
    For(i,1,n) cout << ans[i] << endl;
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
