void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if ((n == 2 || n == 3) && a == b) {
        cout << "NO\n";
        return;
    }
    
    if (a != 1 && b != 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (a == 1) {
        vec2<int> ans(n, vec<int>(n, 1));
        int cnt = n - b;
        for (int i = 0; i < cnt; i++) {
            ans[i][i + 1] = ans[i + 1][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            ans[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    } else {
        vec2<int> ans(n, vec<int>(n, 0));
        int cnt = n - a;
        for (int i = 0; i < cnt; i++) {
            ans[i][i + 1] = ans[i + 1][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
}
