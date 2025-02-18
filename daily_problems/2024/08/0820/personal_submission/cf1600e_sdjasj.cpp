void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            l = i + 1;
        } else {
            break;
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (a[i - 1] > a[i]) {
            r = n - i + 1;
        } else {
            break;
        }
    }
    // cout << l << " " << r << endl;
    if (l % 2 == 1 || r % 2 == 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}