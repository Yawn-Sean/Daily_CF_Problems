/*
    Bonelight * v *
    20241017：CF,Goodnight
    No Coding , No Bug
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
    vector<int> a(n), ls(5050), rs(5050);
    for(int i = 0; i < n; i ++) {cin >> a[i];}
    for(int i = 0; i < n; i ++) rs[a[i]] = i;
    for(int i = n - 1; i >= 0; i --) ls[a[i]] = i;
    
    vector<int> dp(n + 1);
    for(int i = 0; i < n; i ++){
        vector<int> vis(5050);
        int r = 0, v = 0;
        for(int j = i; j < n; j ++){
            if(i > ls[a[j]]) break;
            if(!vis[a[j]]){
                vis[a[j]] = 1;
                r = max(r, rs[a[j]]);
                v ^= a[j];
            }
            if(j == r) {
                dp[j + 1] = max(dp[j + 1], dp[i] + v);
            }
        }
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }
    cout << dp[n] << endl;
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
