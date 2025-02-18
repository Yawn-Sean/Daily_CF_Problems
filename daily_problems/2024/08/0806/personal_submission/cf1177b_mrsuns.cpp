void Solve() {
    int k;cin >> k;
    for (int i = 1, c = 9;;i++, c *= 10) {
        if (k <= c * i) {
            int p = (k + i - 1) / i;
            int res = 1;for (int j = 1;j <= i - 1;j++) res *= 10;
            res = res + p - 1;
            cout << to_string(res)[k - i * (p - 1) - 1] << endl;
            return;
        }
        k -= c * i;
    }
}
