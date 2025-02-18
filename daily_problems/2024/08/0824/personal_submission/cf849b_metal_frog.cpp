void solve() {
    int n;
    cin >> n;
    vector<ll> y(n + 1);
    set<ll> cnt;
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
        cnt.insert(y[i]);
    }
    if (sz(cnt) == 2) {
        cout << "Yes\n";
        return;
    }
    // 1 and 2 in one group
    {
        ll k = y[2] - y[1];
        ll b1 = y[1] - k;
        ll b2;
        vector<ll> notInLine;
        for (ll x = 1; x <= n; x++) {
            if (k * x + b1 != y[x]) {
                notInLine.emplace_back(x);
                b2 = y[x] - k * x;
            }
        }
        bool okay = (sz(notInLine) != 0);
        for (ll x : notInLine) {
            if (k * x + b2 != y[x]) {
                okay = false;
            }
        }
        if (okay && b2 != b1) {
            cout << "Yes\n";
            return;
        }
    }
    // 2 and 3 in one group
    {
        ll k = y[3] - y[2];
        ll b1 = y[2] - k * 2LL;
        ll b2;
        vector<ll> notInLine;
        for (ll x = 1; x <= n; x++) {
            if (k * x + b1 != y[x]) {
                notInLine.emplace_back(x);
                b2 = y[x] - k * x;
            }
        }
        bool okay = (sz(notInLine) != 0);
        for (ll x : notInLine) {
            if (k * x + b2 != y[x]) {
                okay = false;
            }
        }
        if (okay && b2 != b1) {
            cout << "Yes\n";
            return;
        }
    }
    // 1 and 3 in one group
    {
        // k = (y3 - y1) / (x3 - x1)
        ll b1 = y[1] * 2LL - (y[3] - y[1]);
        ll b2;
        vector<ll> notInLine;
        for (ll x = 1; x <= n; x++) {
            if ((y[3] - y[1]) * x + b1 != y[x] * 2LL) {
                notInLine.emplace_back(x);
                b2 = y[x] * 2LL - (y[3] - y[1]) * x;
            }
        }
        bool okay = (sz(notInLine) != 0);
        for (ll x : notInLine) {
            if ((y[3] - y[1]) * x + b2 != y[x] * 2LL) {
                okay = false;
            }
        }
        if (okay && b2 != b1) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}
