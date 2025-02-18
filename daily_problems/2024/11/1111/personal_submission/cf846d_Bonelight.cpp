/*
    Bonelight * v *
    20241108：要难铜了兄弟们
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>

//  二分
void solve(){
    int n,m,k,q; cin >> n >> m >> k >> q;
    vector<vector<int>>  g(n + 1, vector<int>(m + 1, INF)), 
                        pre(n + 1, vector<int>(m + 1));
    
    while(q --) {int x,y,t; cin >> x >> y >> t; g[x][y] = t;}

    int l = -1, r = INF;
    while(l + 1 < r){
        int ok = 0;
        int mid = (l + r) / 2;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                pre[i][j] = (g[i][j] <= mid? 1:0);  
            }
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                pre[i][j] += pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];  
            }
        }
        
        for(int i = k; i <= n; i ++){
            for(int j = k; j <= m; j ++){
                int sum = pre[i][j] + pre[i - k][j - k] - pre[i - k][j] - pre[i][j - k];
                if(sum == k*k) {ok = 1; break;}
            }
        }

        if(ok) r = mid;
        else l = mid;
    }
    if(r == INF) cout << -1 << endl;
    else cout << r << endl;
}

// 二维滑动窗口最大值
void solve2(){
    int n,m,k,q; cin >> n >> m >> k >> q;
    vector<vector<int>>  g(n + 1, vector<int>(m + 1, INF)), 
                        MX(n + 1, vector<int>(m + 1));
    
    while(q --) {int x,y,t; cin >> x >> y >> t; g[x][y] = t;}

    int ans = INF;
    for(int i = 1; i <= n; i ++){
        deque<int> q;
        for(int j = 1; j <= m; j ++){
            while(q.size() && g[i][q.back()] <= g[i][j]) q.pop_back();
            while(q.size() && j - q.front() >= k) q.pop_front();
            q.push_back(j);
            if(j >= k){
                MX[i][j] = g[i][q.front()];
            }
        }
    }

    for(int i = k; i <= m; i ++){
        deque<int> q;
        for(int j = 1; j <= n; j ++){
            while(q.size() && MX[q.back()][i] <= MX[j][i]) q.pop_back();
            while(q.size() && j - q.front() >= k) q.pop_front();
            q.push_back(j);
            if(j >= k) ans = min(MX[q.front()][i], ans);
        }
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
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
