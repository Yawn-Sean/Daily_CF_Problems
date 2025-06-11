/*
    Bonelight * v *
    20241108：要难铜了兄弟们
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,m; cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i ++) cin >> g[i];
    
    int ans = INF;
    int hp = 0;
    for(int i = 0; i < n; i ++){
        int ok = 1;
        for(int j = 0; j < m; j ++){
            int cnt = 4;
            if(i == 0 || i == n - 1) cnt --;
            if(j == 0 || j == m - 1) cnt --;
            if(g[i][j] == 'A'){
                ans = min(ans, cnt);
            } else ok = 0, hp = 1;
        }
        
        if(ok){
            int cnt = 2;
            if(i == 0 || i == n - 1) cnt --;
            ans = min(ans, cnt);
        } 
    }

    for(int i = 0; i < m; i ++){
        int ok = 1;
        for(int j = 0; j < n; j ++){
            if(g[j][i] != 'A') ok = 0;
        }
        if(ok){
            int cnt = 2;
            if(i == 0 || i == m - 1) cnt --;
            ans = min(ans, cnt);
        }
    }
    
    if(!hp) ans = 0;
    if(ans == INF) cout << "MORTAL" << endl;
    else cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1; cin >> T;
    while(T --){
        solve();
    }
}
