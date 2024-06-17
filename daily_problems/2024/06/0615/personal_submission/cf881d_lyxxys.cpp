#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200, inf = 0x3f3f3f3f, P = 998244353;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
vector <string> g(N);
array<int,2> Pre[N][N];
bool vis[N][N];
int endx, endy, n, m;

array<int,2> op(char c){
    cout << c << "\n" << flush;
    int x, y;
    cin >> x >> y;
    return {x, y};
}
void dfs(int sx, int sy){
    if (g[sx][sy] == 'F') endx = sx, endy = sy;
    for (int i = 0; i < 4; ++ i){
        int x = sx+dx[i], y = sy+dy[i];
        if (x < 1 || x > n || y < 1 || y > m || vis[x][y]) continue;
        if (g[x][y] == '*') continue;
        Pre[x][y] = {sx, sy};
        vis[x][y] = true;
        dfs(x, y);
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        cin >> g[i], g[i] = " " + g[i];
    vis[1][1] = true, dfs(1, 1);
    vector <array<int,2>> path;
    {
        int x = endx, y = endy;
        while (x != 1 || y != 1){
            path.push_back({x, y});
            int nx = Pre[x][y][0], ny = Pre[x][y][1];
            x = nx, y = ny;
        }
    }
    path.push_back({1, 1});
    reverse(path.begin(), path.end());
    int len = path.size();
    bool flg1 = true, flg2 = true;
    string ud = "UD", lr = "LR";

    for (int i = 1; i < len; ++ i){
        int tox = path[i][0] - path[i-1][0], toy = path[i][1] - path[i-1][1];
        if (tox==0){
            if (flg1){
                flg1 = false;
                int y = op('L')[1];
                if (y == path[i][1]) lr = "RL";
                else op('R');
            }
            else op(lr[toy>0]);
        }
        else {
            if (flg2){
                flg2 = false;
                int x = op('U')[0];
                if (x == path[i][0]) ud = "DU";
                else op('D');
            }
            else op(ud[tox>0]);
        }
    }
}
