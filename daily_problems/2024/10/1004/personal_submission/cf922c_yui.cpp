void solve() {
    int n, k;
    cin >> n >> k;

    set<int> rec;
    for (int i = 1; i <= k; i++) {
        if (rec.contains(n % i)) {
            cout << "No\n";
            return;
        } else {
            rec.insert(n % i);
        }
    }

    cout << "Yes\n";
}
