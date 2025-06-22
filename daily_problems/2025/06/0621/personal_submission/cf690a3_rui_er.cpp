int T, n, r, a[7];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n >> r;
        rep(i, 1, n - 1) cin >> a[i];
        int sum = accumulate(a + 1, a + n, 0);
        cout << (r - sum % n + n) % n + 1 << endl;
    }
    return 0;
}
