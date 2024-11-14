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
#define tiii tuple<int,int,int>

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for(int i = 0; i < n; i ++){
        string s; cin >> s;
        for(int j = 0; j < m; j ++) g[i][j] = s[j] - '0';
    }

    int ans = INF;
    for(int i = 0; i < n-4; i ++){ // 上边界
        vector<int> cnt(m);
        for(int j = i + 1; j < i + 4; j ++){
            for(int k = 0; k < m; k ++){
                cnt[k] += g[j][k];
            }
        }

        for(int j = i+4; j < n; j ++){ // 下边界
            vector<int> pre = cnt;
            for(int k = 0; k < m; k ++) pre[k] += 2 - g[i][k] - g[j][k];
            for(int k = 1; k < m; k ++) pre[k] += pre[k - 1];
            int mi = INF;
            //枚举左边界 k-3, 处理右边界 k
            for(int k = m-1; k-3 >= 0; k --){
                int dr = j-i-1-cnt[k]; // 右边界的处理次数
                mi = min(mi, pre[k-1] + dr);
                int dl = j-i-1-cnt[k-3]; // 左边界的处理次数
                ans = min(ans, mi - pre[k-3] + dl);
            }
            for(int k = 0; k < m; k ++) cnt[k] += g[j][k];
        }
    }
    cout << ans << endl;
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
