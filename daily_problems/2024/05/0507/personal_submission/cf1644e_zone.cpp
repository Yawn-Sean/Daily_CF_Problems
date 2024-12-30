void solve() {
    int n, m;
    string s;
    cin >> n >> s;
    m = s.size();
    int cntR = 0, cntD = 0;
    int pos = -1;
    for (int i = 0; i < m; i ++ ) {
        if (s[i] != s[0]) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << n << endl;
        return;
    }
    i64 ans = pos + 1LL * (n - pos) * n;
    for (int i = pos; i < m; i ++ ) {
        cntR += s[i] == 'R';
        cntD += s[i] == 'D';
    }
    cout << ans - 1LL * cntR * cntD << "\n";
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt --) {
        solve();
    }
    return 0;
}
