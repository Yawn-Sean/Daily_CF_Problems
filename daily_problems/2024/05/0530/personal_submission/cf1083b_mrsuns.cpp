void Solve() {
    int n, k;cin >> n >> k;
    string A, B;cin >> A >> B;
    A = ' ' + A, B = ' ' + B;
    int pre = 1, res = 0;
    for (int i = 1;i <= n;i++) {
        pre <<= 1;
        if (B[i] == 'a') pre--;
        if (A[i] == 'b') pre--;
        if (pre >= k) {
            res += k * (n - i + 1);
            break;
        }
        else {
            res += pre;
        }
    }
    cout << res << endl;

}
