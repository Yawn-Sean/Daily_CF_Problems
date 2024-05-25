int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> cnt(n + 1, 0);
    set<int> S;
    vector<bool> record(n + 1, false);
    
    for (auto x : a) {
        auto it = S.upper_bound(x);
        if (it != S.end()) {
            auto y = *it;
            it ++;
            if (it == S.end()) {
                cnt[y] ++;
            }
        }
        else {
            record[x] = true;
        }
        S.insert(x);
    }
    int mx = -inf, res = 0;
    for (int i = 1; i <= n; i ++) {
        int val = cnt[i] - record[i];
        if (val > mx) {
            mx = val;
            res = i;
        }
    }
    cout << res << endl;
}