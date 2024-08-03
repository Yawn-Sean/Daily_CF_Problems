int n, m;

void solve() {
    cin >> n >> m;
    vector<int> row(n), col(m);
    cin >> row;
    cin >> col;
    vector<vector<int>> res(n, vector<int>(m, 0));
    int a = col[0], b = row[0];
    for (int i = 1; i < n; i ++) {
        res[i][0] = row[i];
        a ^= row[i];
    }
    for (int i = 1; i < m; i ++) {
        res[0][i] = col[i];
        b ^= col[i];
    }
    
    if (a != b) {
        cout << "NO" << endl;
        return;
    }
    res[0][0] = a;
    cout << "YES" << endl;
    for (auto& vec : res) {
        cout << vec << endl;
    }
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}