int a, b;

void solve() {
    cin >> a >> b;
    if (a < b) {
        cout << -1 << endl;
        return;
    }
    if (a == b) {
        cout << a << endl;
        return;
    }
    auto cal = [&](int x) {
        int t = x / b / 2 * 2;
        return (double)x / t;
    };
    
    cout << min(cal(a + b), cal(a - b)) << endl;
}