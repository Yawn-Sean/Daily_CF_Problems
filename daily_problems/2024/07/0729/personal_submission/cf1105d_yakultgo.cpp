#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
typedef pair<int, int> pi;
int n, m, p;
char mp[N][N];
struct node {
    int x, y, t;
};
queue<node> q[10];
int s[N], ans[N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (isdigit(mp[i][j])) {
                ans[mp[i][j] - '0']++;
                q[mp[i][j] - '0'].push({i, j, 0});
            }
        }
    }
    while (1) {
        bool flag = 1;
        for (int i = 1; i <= p; i++) {
            if (!q[i].empty()) {
                flag = 0;
            }
        }
        if (flag) break;
        for (int i = 1; i <= p; i++) {
            int step = s[i];
            while (step--) {
                if (q[i].empty()) break;
                int tmp = q[i].front().t;
                while (!q[i].empty()) {
                    node u = q[i].front();
                    if (u.t != tmp) break;
                    q[i].pop();
                    for (int e = 0; e < 4; e++) {
                        int nx = u.x + dx[e], ny = u.y + dy[e];
                        if (mp[nx][ny] == '.' && nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                            mp[nx][ny] = i + '0';
                            ans[i]++;
                            q[i].push({nx, ny, tmp + 1});
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= p; i++) cout << ans[i] << ' ';
    return 0;
}