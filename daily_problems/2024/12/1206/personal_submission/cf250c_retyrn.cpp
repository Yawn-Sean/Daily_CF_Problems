int n, k;

void solve() {
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if (em(a) or a.back() != x) {
            a.push_back(x);
        }
    }
    n = sz(a);
    vector<vector<int>> pos(k + 1);
    
    for (int i = 0; i < n; i ++) {
        pos[a[i]].pbk(i);
    }
    
    int sum = n - 1;
    int mn = inf, res = -1;
    
    for (int i = 1; i <= k; i ++) {
        if (em(pos[i])) continue;
        int cur = sum;
        for (auto x : pos[i]) {
            if (x == 0 or x == n - 1) {
                cur -= 1;
            }
            else {
                cur -= 2;
                if (a[x - 1] != a[x + 1]) cur += 1;
            }
        }
        if (cur < mn) {
            mn = cur;
            res = i;
        }
    }
    
    cout << res << endl;
}