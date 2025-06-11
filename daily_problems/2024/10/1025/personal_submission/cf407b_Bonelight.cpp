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
#define INF 2e14
#define pii pair<int,int>


void solve(){
    int n; cin >> n;
    int MOD = 1e9 + 7;
    auto M = [&](int x){return (x % MOD + MOD) % MOD;};

    vector<int> to(n+2);
    for(int i = 1; i <= n; i ++) cin >> to[i];
    to[n+1] = n;

    vector<int> dp(n+2), pre(n + 1);
    dp[1] = 1;
    int ans = n;

    for(int i = 1; i <= n; i ++){
        dp[i] = M(M(pre[i - 1] - pre[to[i] - 1]) + 2);
        pre[i] = M(pre[i - 1] + dp[i]);
    }

    cout << pre[n] << endl;
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
