int n, k;

int ask(int x, int y) {
    cout << 1 << ' ' << x << ' ' << y << endl;
    cout.flush();
    string s;
    cin >> s;
    return s[0] == 'T';
}

int cal(int l, int r) {
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (ask(mid, mid + 1)) r = mid;
        else l = mid + 1;
    }
    return r;
}
void solve() {
    cin >> n >> k;
    int x = cal(1, n), y = cal(1, x - 1);
    if (y == 0 or !ask(y, x)) y = cal(x + 1, n);
    
    cout << 2 << ' ' << x << ' ' << y << endl;
    cout.flush();
}