/*
    Bonelight * v *
    20241031：重 走 西 游 路
    登 神 长 阶， 灯 升 长 阶
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<vector<int>> g(n,vector<int>(m));    
    vector<pii> q;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> g[i][j];
            q.push_back({i,j});
        }
    }
    sort(begin(q), end(q), [&](auto X, auto Y){
        auto [x1,y1] = X; auto [x2,y2] = Y;
        return g[x1][y1] > g[x2][y2];
    });

    vector<pii> df = {{1,0},{0,1},{-1,0},{0,-1}};
    auto bound = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    vector<int> X(n * m), sz(n * m, 1);
    iota(begin(X), end(X), 0);
    function<int(int)> f = [&](int o){return X[o] = X[o] == o? o:f(X[o]);};
    auto merge = [&](int xx, int yy){
        int x = f(xx), y = f(yy);
        if(x != y) X[x] = y, sz[y] += sz[x];
    };

    for(auto [x,y]:q){
        for(auto [dx,dy]:df){
            dx += x, dy += y;
            if(bound(dx,dy) && g[dx][dy] >= g[x][y]){
                merge(x*m+y, dx*m+dy);
            }
        }
        if(k % g[x][y] == 0 && sz[f(x*m+y)] >= k / g[x][y]){
            cout << "YES" << endl;
            vector<vector<int>> ans(n, vector<int>(m));
            int v = g[x][y], cnt = k / v;
            function<void(int,int)> dfs = [&](int x, int y){
                if(cnt == 0) return;
                cnt --, ans[x][y] = v;
                for(auto [dx,dy]:df){
                    dx += x, dy += y;
                    if(bound(dx,dy) && ans[dx][dy] == 0 && g[dx][dy] >= v){
                        dfs(dx,dy);
                    }
                }
            }; 
            dfs(x,y);
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < m; j ++){
                    cout << ans[i][j] << ' ';
                }
                cout << endl;
            }
            return;
        }
    }
    cout << "NO" << endl;
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
