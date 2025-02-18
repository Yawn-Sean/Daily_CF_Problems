#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN int(2e5 + 10)
#define MOD int(1e9 + 7)
#define rep(i, start, end) for(int i = start; i <= end; ++i)
#define erp(i, end, start) for(int i = end; i >= start; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;


int di[4][2] = {
    {1, 0},
    {0, -1},
    {0, 1},
    {-1, 0}
};

char dir[] = {'D', 'L', 'R', 'U'};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s[n];
    rep(i, 0, n - 1) cin >> s[i];

    if(k & 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int x, y;
    rep(i, 0, n - 1) rep(j, 0, m - 1) {
        if(s[i][j] == 'X') {
            x = i;
            y = j;
            break;
        }
    }
    vector<vector<int>> d(n, vector(m, -1));
    d[x][y] = 0;
    queue<pii> que;
    que.push({x, y});

    while(!que.empty()) {
        auto[x0, y0] = que.front();
        que.pop();

        rep(i, 0, 3) {
            int nx = x0 + di[i][0], ny = y0 + di[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(d[nx][ny] != -1) continue;
            if(s[nx][ny] == '*') continue;
            d[nx][ny] = d[x0][y0] + 1;
            que.push({nx, ny});
        }
    }

    while(k) {
        --k;
        bool ok = false;
        rep(i, 0, 3) {
            int nx = x + di[i][0], ny = y + di[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(s[nx][ny] == '*') continue;
            if(d[nx][ny] > k) continue;

            x = nx, y = ny;
            cout << dir[i];
            ok = true;
            break;
        }
        if(!ok) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
