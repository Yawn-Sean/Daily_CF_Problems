void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> R(n + 1), C(n + 1);
    vector<int> prefR[2], prefC[2];
    prefR[0].resize(n + 1), prefR[1].resize(n + 1);
    prefC[0].resize(n + 1), prefC[1].resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> R[i];
        prefR[R[i] % 2][i] = 1; 
    }
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
        prefC[C[i] % 2][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            prefR[j][i] += prefR[j][i - 1];
            prefC[j][i] += prefC[j][i - 1];
        }
    }
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 > r2) swap(r1, r2);
        if (c1 > c2) swap(c1, c2);
        if (R[r1] % 2 != R[r2] % 2 || C[c1] % 2 != C[c2] % 2) {
            cout << "NO\n";
            continue;
        }
        if (R[r1] % 2 == 0) {
            if (prefR[1][r2] - prefR[1][r1 - 1] != 0) {
                cout << "NO\n";
            } else if (prefC[1][c2] - prefC[1][c1 - 1] != 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        } else {
            if (prefR[0][r2] - prefR[0][r1 - 1] != 0) {
                cout << "NO\n";
            } else if (prefC[0][c2] - prefC[0][c1 - 1] != 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}
