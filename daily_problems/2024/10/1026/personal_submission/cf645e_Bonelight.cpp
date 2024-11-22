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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    
    vector<int> dp(k), lt(k,-1);
    const int MOD = 1e9 + 7;
    auto M = [&](int x){return (x % MOD + MOD) % MOD;};

    vector<int> idx(k);
    iota(begin(idx), end(idx), 0);
    for(int i = 0; i < s.size(); i ++) lt[s[i] - 'a'] = i;
    sort(begin(idx), end(idx), [&](auto x, auto y){
        return lt[x] < lt[y];
    });

    int tot = 0;
    for(auto ch:s){
        int c = ch - 'a';
        int add = M(tot - dp[c] + 1);
        dp[c] = M(dp[c] + add);
        tot = M(tot + add);
    }

    for(int i = 0; i < n; i ++){
        int c = idx[i % k];
        int add = M(tot - dp[c] + 1);
        dp[c] = M(dp[c] + add);
        tot = M(tot + add);
    }
    cout << M(tot + 1) << endl;
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
