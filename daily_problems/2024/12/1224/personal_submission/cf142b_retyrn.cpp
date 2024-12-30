int n, m;

void solve() {
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == 1) {
        cout << n * m << endl;
        return;
    }
    if (n == 2) {
        if (m % 4 == 2) {
            cout << n + m << endl;
            return;
        }
        cout << (m + m % 2) << endl;
        return;
    }
    
    cout << ((ll)n * m + 1) / 2 << endl;
}