int n, k;

void solve() {
    cin >> n >> k;
    // x x+1 x+2 x+4
    cout << (n * 6 - 1) * k << endl;
    for (int i = 1; i <= n; i ++) {
        cout << (6 * i - 5) * k << ' ' << (6 * i - 4) * k << ' ' << (6 * i - 3) * k << ' ' << (6 * i - 1) * k << endl;
    }
}