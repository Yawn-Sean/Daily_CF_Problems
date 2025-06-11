#define SINGLE
void solve() {
    int n, m;
    cin >> n >> m;
    int cnt = 0, cnt_seg = 0, ok = 0, idx, op;
    vi s(n);
    char ch;
    rep (i, 0, n) {
        cin >> ch;
        if (ch == '.') s[i] = 1, cnt++, ok = 1;
        else if (ok == 1) cnt_seg++, ok = 0;
    }
    cnt_seg += ok;
    rep (i, 0, m) {
        cin >> idx >> ch;
        idx--;
        ch = ch == '.' ? 1 : 0;
        if (ch ^ s[idx]) {
            op = ch ? 1 : -1;
            cnt += op;
            ok = 0;
            if (idx > 0 and s[idx - 1]) ok++;
            if (idx < n - 1 and s[idx + 1]) ok++;
            if (ok == 2) cnt_seg -= op;
            else if (ok == 0) cnt_seg += op;
        }
        cout << cnt - cnt_seg << nl;
        s[idx] = ch;
    } 
}
