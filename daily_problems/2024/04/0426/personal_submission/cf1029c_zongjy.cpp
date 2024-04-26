constexpr int inf = 1E9 + 1;
void solve() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    vector<int> prel(n + 1), prer(n + 1, inf), sufl(n + 1), sufr(n + 1, inf);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        prel[i + 1] = max(prel[i], l[i]);
        prer[i + 1] = min(prer[i], r[i]);
    }
    for (int i = n; i > 0; --i) {
        sufl[i - 1] = max(sufl[i], l[i - 1]);
        sufr[i - 1] = min(sufr[i], r[i - 1]);
    }
    int ans = 0, tl, tr;
    for (int i = 1; i <= n; i++) {
        tl = max(prel[i - 1], sufl[i]);
        tr = min(prer[i - 1], sufr[i]);
        ans = max(ans, tr - tl);
    }
    cout << ans << '\n';
}