/*
    abcdefghijklmnopqrstuvwxyz
    DLRU
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }
    if (k % 2 == 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    vector<vector<int>> dis(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dis[sx][sy] = 0;
    string ss = "DLRU";
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] != '*' && dis[nx][ny] == -1) {
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    while (k) {
        bool ok = 0;
        for (int i = 0; i < 4; i++) {
            int nx = sx + dir[i][0];
            int ny = sy + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] != '*' && dis[nx][ny] <= k - 1) {
                cout << ss[i];
                sx = nx;
                sy = ny;
                k--;
                ok = 1;
                break;
            }
        }
        if (!ok) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
