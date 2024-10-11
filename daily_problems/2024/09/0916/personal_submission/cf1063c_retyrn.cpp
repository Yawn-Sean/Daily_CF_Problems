int n;

int ask(int x, int y) {
    cout << x << ' ' << y << endl;
    cout.flush();
    string s;
    cin >> s;
    return s[0] == 'b';
}
void solve() {
    cin >> n;
    int l = 0, r = 1e9;
    int flag = ask(r, r);
    for (int i = 0; i < n - 1; i ++) {
        int mid = (l + r) >> 1;
        if (ask(mid, mid) == flag) r = mid;
        else l = mid;
    }
    cout << l << ' ' << r << ' ' << r << ' ' << l << endl;
    cout.flush();
}