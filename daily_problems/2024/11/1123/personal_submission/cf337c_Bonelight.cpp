/*
    Bonelight * v *
    20241113：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define VC vector<int>
#define MAT vector<VC>

void solve(){   
    const int MOD = 1e9+9;
    int n,m,k; cin >> n >> m >> k;
    int v1 = min(m, n - n / k), v2 = m - v1; 
    v1 -= (k-1) * v2;
    auto qpow = [&](int x, int y){
        int res = 1;
        while(y >= 1){
            if(y & 1) res = res * x % MOD;
            y >>= 1;
            x = x * x % MOD;
        }
        return res;
    };
    cout << ((k * (qpow(2,v2 + 1) - 2 + MOD)) + v1) % MOD << endl;
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
