
const ll mod = 998244353;

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> x(q), y(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
    }
    ll ans = 1;
    unordered_set<int> coloredRow, coloredCol;
    for (int i = q - 1; i >= 0; i--) {
        int row = x[i], col = y[i];
        bool coverRow = true, coverCol = true;
        if (coloredRow.find(row) == coloredRow.end() && coloredCol.size() != m) {
            coverRow = false;
        }
        if (coloredCol.find(col) == coloredCol.end() && coloredRow.size() != n) {
            coverCol = false;
        }
        if (!coverCol || !coverRow) {
            ans *= k; ans %= mod;
        }
        coloredCol.insert(col);
        coloredRow.insert(row);
    }
    cout << ans << "\n";
}
