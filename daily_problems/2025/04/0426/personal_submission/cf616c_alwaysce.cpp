#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (auto& x: grid) { cin >> x;}

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    auto f = [&](int x, int y) {
        return x * m + y;
    };

    DSU dsu(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (grid[nx][ny] == '.') {
                        dsu.merge(f(i, j), f(nx, ny));
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                cout << '.';
            } else {
                int ans = 1;
                set<int> st;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '*') continue;
                    
                    int fa = dsu.find(f(nx, ny));
                    if (st.count(fa)) continue;
                    st.insert(fa);
                    ans += dsu.size(fa);
                }
                cout << ans % 10;
            }
        }
        cout << '\n';
    }
    
    return 0;
}
