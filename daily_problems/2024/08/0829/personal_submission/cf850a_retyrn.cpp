int n;
using ai5 = array<int, 5>;

void solve() {
    cin >> n;
    if (n >= 34) {
        cout << 0 << endl;
        return;
    }
    vector<ai5> a(n);
    for (auto& x : a) {
        for (auto& y : x) {
            cin >> y;
        }
    }
    vector<int> res;
    
    for (int i = 0; i < n; i ++) {
        bool ok = true;
        for (auto j = 0; j < n and ok; j ++) {
            if (i == j) continue;
            for (int k = 0; k < n and ok; k ++) {
                if (i == k or j == k) continue;
                int sum = 0;
                for (int t = 0; t < 5; t ++) {
                    sum += (a[j][t] - a[i][t]) * (a[k][t] - a[i][t]);
                }
                if (sum > 0) ok = false;
            }
        }
        if (ok) {
            res.push_back(i + 1);
        }
    }
    cout << sz(res) << endl;
    for (auto x : res) {
        cout << x << endl;
    }
    
}