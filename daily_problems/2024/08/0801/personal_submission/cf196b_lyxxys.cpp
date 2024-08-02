#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 100050, mod = 1e9 + 7;
const double inf = 1e9;
double eps = 1e-10;
string g[1550];
array<int,2> bias[1550][1550];
bool vis[1550][1550];

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        cin >> g[i];
        g[i] = " " + g[i];
    }

    const int dto[] = {-1,0,1,0,-1};
    function<bool(int,int)> bfs = [&](int sx, int sy){
        queue <array<int,2>> Q;
        Q.push({sx, sy});
        vis[sx][sy] = true;
        bias[sx][sy] = {sx, sy};

        while (!Q.empty()){
            auto t = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++ i){
                int x = t[0]+dto[i], y = t[1]+dto[i+1];
                int px = ((x-1)%n + n)%n+1, py = ((y-1)%m + m)%m+1;
                if (g[px][py]=='#') continue;
                if (vis[px][py]){
                    if (bias[px][py] != array<int,2>({x,y})) return true;
                    continue;
                } else {
                    vis[px][py] = true;
                    bias[px][py] = {x, y};
                    Q.push({x, y});
                }
            }

        }
        return false;
    };

    int sx = -1, sy = -1;
    for (int i = 1; i <= n; ++ i){
        if (sx != -1) break;
        for (int j = 1; j <= m; ++ j){
            if (g[i][j] == 'S'){
                sx = i, sy = j;
                break;
            }
        }
    }

    if (bfs(sx, sy)) cout << "Yes\n";
    else cout << "No\n";
}
