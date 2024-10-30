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
    int n,m; cin >> n >> m;
    vector<string> g(n);
    vector<pii> df = {{1,0},{0,1},{-1,0},{0,-1}};
    for(int i = 0; i < n; i ++) cin >> g[i];

    auto round = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m; 
    };

    auto check = [&](int x, int y){
        int cnt = 0;
        for(auto [dx,dy]:df){
            dx += x, dy += y;
            if(round(dx,dy) && g[dx][dy] == '.') cnt ++;
        }
        return cnt == 1;
    };

    for(int i = 0; i < n; i ++) cin >> g[i];
    // #BFS
    queue<pii> q;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(check(i,j) && g[i][j] == '.') q.push({i,j});
        }
    }
    while(q.size()){
        auto [x,y] = q.front(); q.pop();
        if(g[x][y] != '.') continue;

        for(int k = 0; k < 4; k ++){
            int dx = x + df[k].first, dy = y + df[k].second;
            if(round(dx,dy) && g[dx][dy] == '.'){
                if(k == 0) g[x][y] = '^', g[dx][dy] = 'v';
                if(k == 1) g[x][y] = '<', g[dx][dy] = '>';
                if(k == 2) g[x][y] = 'v', g[dx][dy] = '^';
                if(k == 3) g[x][y] = '>', g[dx][dy] = '<';
                for(int nk = 0; nk < 4; nk ++){
                    int nnx = dx + df[nk].first, nny=dy+df[nk].second;
                    if(check(nnx,nny) && g[nnx][nny] == '.') q.push({nnx,nny}); 
                }
            }
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(g[i][j] == '.'){
                cout << "Not unique" << endl;
                return;
            }
        }
    }
    for(int i = 0; i < n; i ++) cout << g[i] << endl;
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
