int x;

void solve() {
    cin >> x;
    // 只需要 (n / m) ^ 2个0即可
    // n ^ 2 - (n / m) ^ 2
    // (n + n / m)(n - n / m) = x
    if (x == 0) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    
    for (int i = 1; i < x / i; i ++) {
        if (x % i) continue;
        int a = i, b = x / i;
        if (a == b) continue;
        if ((a + b) & 1) continue;
        int n = (a + b) >> 1;
        int nm = n - a;
        int m = n / nm;
        // n / m >= nm
        // m <= n / nm
        if (n / m != nm) m --;
        if (m <= 0 or n / m != nm) continue;
        cout << n << ' ' << m << endl;
        return;
    }
    cout << -1 << endl;
}