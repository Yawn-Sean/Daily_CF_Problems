int n;

void solve() {
    cin >> n;
    if (n == 0) {
        cout << "a" << endl;
        return;
    }
    vector<pii> f(n + 1, mpr(inf, -1));
    f[0] = mpr(0, 0);
    
    for (int i = 0; i <= n; i ++) {
        if (f[i].fi == inf) continue;
        int step = f[i].fi + 1;
        for (int x = 1; x * (x - 1) / 2 + i <= n; x ++) {
            int to = x * (x - 1) / 2 + i;
            if (step < f[to].fi) {
                f[to].fi = step;
                f[to].se = x;
            }
        }
    }
    
    string s;
    char c = 'a';
    while (n > 0) {
        int x = f[n].se;
        s += string(x, c);
        n -= x * (x - 1) / 2;
        c ++;
    }
    cout << s << endl;
}