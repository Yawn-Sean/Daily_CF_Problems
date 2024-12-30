void Solve() {
    int n, k;cin >> n >> k;
    int qr;
    vector<int> cnt(n + 1), a(n + 1);
    for (int i = 1;i <= k + 1;i++) {
        cout << "? ";
        for (int j = 1;j <= k + 1;j++) {
            if (j == i) continue;
            cout << j << " ";
        }
        cout << endl;
        cin >> qr >> a[qr];
        cnt[qr] += 1;
    }
    int mx = *max_element(a.begin(), a.end());
    for (int i = 1;i <= k + 1;i++) {
        if (a[i] == mx) {
            cout << "! ";
            cout << cnt[i] << endl;
            return;
        }
    }
}
