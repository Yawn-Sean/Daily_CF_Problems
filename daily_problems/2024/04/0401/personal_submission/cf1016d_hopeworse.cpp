

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n + 1, vector<int>(m + 1));
    int nn, mm, n0 = 0, m0 = 0;

    for (int i = 1; i < n; i++) {
        cin >> mp[i][m];
        n0 ^= mp[i][m];
    }
    cin >> nn;
    for (int i = 1; i < m; i++) {
        cin >> mp[n][i];
        m0 ^= mp[n][i];
    }
    cin >> mm;
    nn ^= m0;
    mm ^= n0;
    mp[n][m] = mm;
    if (nn != mm)cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << mp[i][j] << " ";
            }
            cout << endl;
        }
    }


}
