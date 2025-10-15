/**
 * https://codeforces.com/problemset/problem/676/D
 * D. Theseus and labyrinth
 * Solver: nhant
 * 2025-04-18 03:53:12
 * https://codeforces.com/problemset/submission/676/316020583
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 1002;
const int MAX_TIME = 10000000;
char s[N][N];
int mask[N][N];
int dist[N][N][4];
string dict = "+-|^><vLRUD*";
int dm[] = {
    0b1111,
    0b1010,
    0b0101,
    0b0001,
    0b0010,
    0b1000,
    0b0100,
    0b0111,
    0b1101,
    0b1110,
    0b1011,
    0b0000
};
int dirs[][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
            for (int k = 0, z = (int) dict.size(); k < z; k++) {
                if (s[i][j] == dict[k]) {
                    mask[i][j] = dm[k];
                }
            }
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = MAX_TIME;
            }
        }
    }
    int tx, ty, mx, my;
    cin >> tx >> ty >> mx >> my;
    tx--; ty--; mx--; my--;
    queue<array<int,3>> q;
    q.push({tx, ty, 0});
    dist[tx][ty][0] = 0;
    while (q.size() > 0) {
        array<int,3> u = q.front(); // no ref, ref is invalid after pop
        q.pop();
        int x = u[0], y = u[1], t = u[2];
        if (x == mx && y == my) break;
        if (dist[x][y][t] + 1 < dist[x][y][(t+1)&3]) {
            dist[x][y][(t+1)&3] = dist[x][y][t] + 1;
            q.push({x,y,(t+1)&3});
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '*') continue;
            if (((mask[x][y]>>((4-t+i)&3)) & (mask[nx][ny]>>((4-t+i+2)&3)) & 1) == 1 && dist[x][y][t] + 1 < dist[nx][ny][t]) { // ==1 without &1 -> wrong
                dist[nx][ny][t] = dist[x][y][t] + 1;
                q.push({nx,ny,t});
            }
        }
    }
    int res = MAX_TIME;
    for (int i = 0; i < 4; i++) {
        res = min(res, dist[mx][my][i]);
    }
    cout << (res == MAX_TIME ? -1 : res) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
