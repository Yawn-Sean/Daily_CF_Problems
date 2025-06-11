void solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int prefix = 1, suffix = 1;
    for (int i = 1; i < n; i++) {
        if (num[i] > num[i - 1]) prefix++;
        else break;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (num[i] > num[i + 1]) suffix++;
        else break;
    }
    if (prefix % 2 == 1 || suffix % 2 == 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}
