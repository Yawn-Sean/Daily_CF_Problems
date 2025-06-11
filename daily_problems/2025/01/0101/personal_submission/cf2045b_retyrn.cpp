ll n, d, s;

void solve() {
    cin >> n >> d >> s;
    n /= s;
    d /= s;
    
    if (n <= d + 1) {
        cout << n * s << endl;
        return;
    }

    chmin(n, d * 2);
    for (int i = 2; i <= 1000000; i ++) {
        if (n % i) continue;
        if (n - n / i <= d) {
            cout << n * s << endl;
            return;
        }
    }
    cout << (n - 1) * s << endl;
    
}