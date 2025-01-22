/*
    Bonelight * v *
    20241024：CF,Goodnight
    登神长阶， 灯 升 长 阶
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
#define INF 2e14
#define pii pair<int,int>
 
void solve(){
    int n; cin >> n;
    vector<int> X(n + 1), deps(n + 1);
    iota(begin(X), end(X), 0ll);
 
    const int MOD = 1e9 + 7;
    auto M = [&](int x){return (x % MOD + MOD) % MOD;};
    
    function<int(int)> f = [&](int o){
        if(X[o] == o) return o;
        int p = f(X[o]);
        deps[o] = M(deps[o] + deps[X[o]]);
        return X[o] = p;
    };
 
    auto merge =[&](int xx, int yy, int val){
        int x = f(xx), y = f(yy);
        if(x != y){
            X[x] = y;
            deps[x] = M(M(deps[yy] - deps[xx]) + val);
        }
    };
 
    int sum = 0;
    for(int i = 1; i <= n; i ++){
        int k; cin >> k;
        while(k --){
            int p,x; cin >> p >> x;
            f(p);
            int dep = M(M(2*deps[p]) + x);
            sum = M(sum + M(deps[p] + x));
            merge(p,i,dep);
        }

    }

    cout << sum << endl;
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
