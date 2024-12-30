/*
    dfs，有点像回溯
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    int ans = 0;

    vector<vector<int>> vis(n, vector<int>(m));
    vector<vector<int>> x;
    auto dfs = [&] (auto&& dfs, int i, int j) -> void {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '#') return;
        if (vis[i][j]) return;
        vis[i][j] = 1;

        grid[i][j] = 'B';
        x.push_back({0, i + 1, j + 1});

        dfs(dfs, i + 1, j);
        dfs(dfs, i - 1, j);
        dfs(dfs, i, j + 1);
        dfs(dfs, i, j - 1);

        if ((i > 0 && grid[i - 1][j] == 'B') || (i < n - 1 && grid[i + 1][j] == 'B') 
        || (j > 0 && grid[i][j - 1] == 'B') || (j < m - 1 && grid[i][j + 1] == 'B')) {
            x.push_back({2, i + 1, j + 1});
            x.push_back({1, i + 1, j + 1});
            grid[i][j] = 'R';
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') dfs(dfs, i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'R') ans += 200;
            else if (grid[i][j] == 'B') ans += 100;
        }
    }
    // cout << ans << "\n";
    cout << x.size() << "\n";
    for (auto i : x) {
        if (i[0] == 0) cout << "B ";
        if (i[0] == 1) cout << "R ";
        if (i[0] == 2) cout << "D ";
        cout << i[1] << " " << i[2] << "\n";
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
