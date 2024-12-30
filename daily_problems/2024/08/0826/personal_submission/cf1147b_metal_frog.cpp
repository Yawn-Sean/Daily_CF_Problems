const int N = 200007;
pii seg[N];

bool check(int k, int n, int m) {
    map<pii, bool> checker;
    for (int i = 0; i < m; i++) {
        checker[seg[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        int newx = (seg[i].first + k - 1) % n + 1, newy = (seg[i].second + k - 1) % n + 1;
        if (newx > newy) swap(newx, newy);
        if (checker[{newx, newy}]) {
            checker[{newx, newy}] = false;
        } else {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> seg[i].first >> seg[i].second;
        if (seg[i].first > seg[i].second) swap(seg[i].first, seg[i].second);
    }

    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            if (check(d, n, m)) {
                cout << "Yes\n";
                return;
            }
            if (d * d != n && d != 1 && check(n / d, n, m)) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}
