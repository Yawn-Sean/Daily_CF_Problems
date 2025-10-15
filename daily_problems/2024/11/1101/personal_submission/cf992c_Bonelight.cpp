/*
    Bonelight * v *
    20241023：CF,Goodnight
    登神长阶， 灯 升 长 阶
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>

void solve(){
    const int MOD = 1e9 + 7;
    auto M = [&](int x){return (x % MOD + MOD) % MOD;};
    auto qmi = [&](int x, int y){
        int res = 1;
        while(y > 0){
            if(y & 1) res = M(res * x); 
            y >>= 1;
            x =  M(x*x);
        }
        return res;
    };

    int n,k; cin >> n >> k;
    if(n == 0) cout << 0 << endl;
    else if(k == 0) cout << M(n * 2) << endl; 
    else{
        cout << M(M(qmi(2,k+1)*M(n)) - M(qmi(2,k) - 1));
    }

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1; 
    while(T --){
        solve();
    }
}
