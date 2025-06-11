int n, m;

void solve() {
    cin >> n >> m;
    cout << gcd(n - 1, m - 1) + 1 << endl;
}