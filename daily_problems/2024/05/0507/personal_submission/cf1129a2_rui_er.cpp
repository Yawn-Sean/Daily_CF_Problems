const int N = 5e3 + 5;

int n, m, a, b, cnt[N], rem[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(rem, 0x3f, sizeof(rem));
    cin >> n >> m;
    rep(i, 1, m) {
        cin >> a >> b;
        ++cnt[a];
        chkmin(rem[a], (b - a + n) % n);
    }
    rep(i, 1, n) {
        int ans = 0;
        rep(j, 1, n) if(cnt[j]) chkmax(ans, (cnt[j] - 1) * n + rem[j] + (j - i + n) % n);
        cout << ans << " \n"[i == n];
    }
    return 0;
}
