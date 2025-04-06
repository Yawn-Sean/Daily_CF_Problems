/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N = 8;

    int dis[9][9][9][9], dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> where[9][9][9][9];

    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            for (int z = 1; z <= N; z ++) {
                for (int k = 1; k <= N; k ++) dis[i][j][z][k] = 1e9;
            }
            queue<vector<int>> q;
            q.push({i, j});
            dis[i][j][i][j] = 0;
            
            while (q.size()) {
                auto v = q.front();
                q.pop();
                int x = v[0], y = v[1];

                for (int z = 0; z < 8; z ++) {
                    int nx = x + dx[z], ny = y + dy[z];
                    if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;  

                    if (dis[i][j][nx][ny] > dis[i][j][x][y] + 1) {
                        dis[i][j][nx][ny] = dis[i][j][x][y] + 1;
                        where[i][j][nx][ny] = {x, y};
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    int n;
    cin >> n;

    vector x(n, 0), y(n, 0);
    vector on(N + 1, vector(N + 1, 0)), dont = on;

    for (int i = 0; i < n; i ++) {
        char a, b;
        cin >> a >> b;
        x[i] = b - '0', y[i] = a - 'a' + 1;
        on[x[i]][y[i]] = 1;
    }

    vector<vector<int>> ans;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if (on[i][j]) {
                dont[i][j] = 1;
                continue;
            }

            int xx = -1, yy = -1;
            while (x.size()) {
                int xxx = x.back(), yyy = y.back();
                x.pop_back(), y.pop_back();
                if (dont[xxx][yyy]) continue;
                xx = xxx, yy = yyy;
                break;
            }     
            if (xx == -1) break;

            vector<vector<int>> path, rpath;
            while (xx != i || yy != j) {
                path.push_back({xx, yy});
                auto next = where[i][j][xx][yy];
                xx = next[0], yy = next[1];
            }
            path.push_back({i, j});

            while (path.size()) {
                auto v = path.back();
                path.pop_back();

                int x = v[0], y = v[1];
                if (on[x][y]) {
                    int lastx = x, lasty = y;
                    while (rpath.size()) {
                        auto v = rpath.back();
                        int xx = v[0], yy = v[1];
                        ans.push_back({lastx, lasty, xx, yy});
                        lastx = xx, lasty = yy;
                        rpath.pop_back();
                    }   
                    on[x][y] = 0;
                    on[lastx][lasty] = 1;
                }
                rpath.push_back({x, y});
            }
            dont[i][j] = 1;
        }
    }

    cout << ans.size() << endl;
    for (auto v : ans) cout << (char) (v[1] + 'a' - 1) << v[0] << '-' << (char) (v[3] + 'a' - 1) << v[2] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
