/*
    Bonelight * v *
    20241101：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>

void solve(){
    string chars = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n, m, k; cin >> n >> m >> k;
    int cnt = 0, each = 0, ex = 0;

    vector<string> g(n);
    for(int i = 0; i < n; i ++) cin >> g[i];
    
    for(int i = 0; i < n; i ++) 
        for(int j = 0; j < m; j ++) 
            if(g[i][j] == 'R') cnt ++;
    
    each = cnt / k, ex = cnt % k;

    vector<string> ans(n, string(m, chars[k - 1]));       
    int now = 0, cur = 0;

    auto check = [&](int x, int y){
        if(cur == k - 1) return;
        ans[x][y] = chars[cur];
            if(g[x][y] == 'R'){
                now ++;
                if(now >= each + (ex > 0)){
                    ex --;
                    now = 0;
                    cur ++;
                }
            } 
    };

    for(int i = 0; i < n; i ++){
        if(i & 1){
            for(int j = m - 1; j >= 0; j --){
                check(i,j);
            }
        } else {
            for(int j = 0; j < m; j ++){
                check(i,j);
            }
        }
    }

    for(auto s:ans) cout << s << endl;
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1; cin >> T;
    while(T --){
        solve();
    }
}
