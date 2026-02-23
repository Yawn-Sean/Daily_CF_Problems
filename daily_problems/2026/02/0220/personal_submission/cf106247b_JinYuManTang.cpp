void solve() {
    int n;
    cin >> n;
    int x = 1;
    vector<int> divisors;
    if (n == 1) {
        divisors.push_back(1);
    } else if (n == 2) {
        cout << -1 << '\n';
        return;
    } else {
        x = 3 << n - 2;
        divisors.push_back(1);
        divisors.push_back(2);
        for (int i = 0; i < n - 2; i++) {
            divisors.push_back(3 << i);
        }
    }
    cout << x << '\n';
    for (int v: divisors) {
        cout << v << ' ';
    }
    cout << '\n';
}
