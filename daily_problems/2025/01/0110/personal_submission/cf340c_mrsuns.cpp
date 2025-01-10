void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int s = 0, res = 0;
    for (int i = 1;i <= n;i++) {
        s += a[i];
        res += i * a[i] - s;
    }
    int A = res * 2;
    for (int i = 1;i <= n;i++) A += a[i];
    int B = n;
    int g = gcd(A, B);
    A /= g, B /= g;
    cout << A << ' ' << B << endl;
}
