const int N = 2e5 + 5;

int T, n, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n >> k;
        rep(i, 1, n) cin >> a[i];
        int len = 0x3f3f3f3f, pos = 0;
        rep(i, 1, n - k) {
            if(a[i + k] - a[i] < len) {
                len = a[i + k] - a[i];
                pos = a[i] + len / 2;
            }
        }
        cout << pos << endl;
    }
    return 0;
}
