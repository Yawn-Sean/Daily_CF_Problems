void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m)), grid2(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            grid2[i][j] = grid[i][j];
        }
    }
    vector<int> maxrow(n), maxcol(m);
    for (int i = 0; i < n; i++) {
        vector<int> tmp = grid[i];
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        maxrow[i] = tmp.size();
        unordered_map<int, int> mp;
        for (int j = 0; j < tmp.size(); j++) {
            mp[tmp[j]] = j + 1;
        }
        for (int j = 0; j < m; j++) {
            grid[i][j] = mp[grid[i][j]];
        }
    }
    for (int j = 0; j < m; j++) {
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            tmp[i] = grid2[i][j];
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        maxcol[j] = tmp.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < tmp.size(); i++) {
            mp[tmp[i]] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            grid2[i][j] = mp[grid2[i][j]];
        }
    }    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] < grid2[i][j]) {
                cout << max(maxrow[i] + (grid2[i][j] - grid[i][j]), maxcol[j]) << " ";
            } else {
                cout << max(maxrow[i], maxcol[j] + (grid[i][j] - grid2[i][j])) << " ";
            }
        }
        cout << endl;
    }
}
