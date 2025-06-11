/*
    Bonelight =^x^=
    20241117: 单枪匹马，无畏粉身碎骨
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>  
#define INF 2e18
#define VC vector<int>
#define MAT vector<VC>
// #define x first
// #define y second

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    const int MOD = 1e9 + 7;
    auto M = [&](int x){return (x % MOD + MOD) % MOD;};
    auto qpow = [&](int x, int y){
        int res = 1;
        while(y > 0){
            if(y & 1) res = M(res * x);
            x = M(x*x); y >>= 1;
        }
        return res;
    };
    auto ni = [&](int x){return qpow(x,MOD - 2);};

    int n,k; cin >> n >> k;
    vector<int> mul(n+1,1), inv(n + 1,1);
    for(int i = 1; i <= n; i ++) mul[i] = M(mul[i - 1] * i);
    
    inv[n] = ni(mul[n]);
    for(int i = n; i > 0; i --) inv[i-1] = M(inv[i] * i); 
    auto div = [&](int x){return M(mul[x-1] * inv[x]);}; 
    
    vector<int> C(n+1,1);
    for(int i = 1; i <= n; i ++) C[i] = M(M(C[i-1] * div(i)) * (k + i - 1));

    vector<int> a(n),val(n);
    for(int i = 0; i < n; i ++) cin >> a[i];

    for(int i = 0; i < n; i ++){
        for(int j = 0; j <= i; j ++){
            int d = i - j;
            val[i] = M(val[i] + M(C[d] * a[j]));
        }
    }

    for(auto i:val) cout << i << ' ';
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; //cin >> T;
    while(T --){
        solve();
    } 
}
