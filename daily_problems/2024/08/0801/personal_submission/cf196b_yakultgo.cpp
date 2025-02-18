#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> str(n);
    for (int i = 0; i < n; i++) cin >> str[i];
    vector<vector<array<int, 3>>> vis(n, vector<array<int, 3>>(m));
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (str[i][j] == 'S') {
                sx = i;
                sy = j;
                str[i][j] = '.';
                break;
            }
        }
    }
    bool flag = false;
    int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    function<void(int, int, int, int)> dfs = [&](int ax, int ay, int cx, int cy) {
        if (flag) return;
        if (vis[cx][cy][0] && (vis[cx][cy][1] != ax || vis[cx][cy][2] != ay)) {
            flag = true;
            return;
        }
        if (vis[cx][cy][0] && vis[cx][cy][1] == ax && vis[cx][cy][2] == ay) return;
        vis[cx][cy][0] = 1;
        vis[cx][cy][1] = ax;
        vis[cx][cy][2] = ay;
        for (int i = 0; i < 4; i++) {
            int nx = (cx + dirs[i][0] + n) % n;
            int ny = (cy + dirs[i][1] + m) % m;
            if (str[nx][ny] == '.') {
                dfs(ax + dirs[i][0], ay + dirs[i][1], nx, ny);
            }
        }
    };
    dfs(sx, sy, sx, sy);
    cout << (flag ? "Yes" : "No") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}