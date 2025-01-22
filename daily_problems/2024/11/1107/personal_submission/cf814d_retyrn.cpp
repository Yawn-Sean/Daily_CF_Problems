const double pi = acos(-1.0);
int n;
using ai3 = array<int, 3>;

void solve() {
    cin >> n;
    vector<ai3> a(n);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 3; j ++) {
            cin >> a[i][j];
        }
    }
    
    sort(all(a), [](ai3& x, ai3& y) {
        return x[2] > y[2];
    });
    
    auto check = [&](ai3& x, ai3& y) -> bool {
        return (ll)(x[0] - y[0]) * (x[0] - y[0]) + (ll)(x[1] - y[1]) * (x[1] - y[1]) <= (ll)(x[2] - y[2]) * (x[2] - y[2]);
    };
    
    vector<int> cnt(n);
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            if (check(a[i], a[j])) {
                cnt[i] ++;
            }
        }
    }
    
    ll res = 0;
    
    for (int i = 0; i < n; i ++) {
        ll r2 = (ll)a[i][2] * a[i][2];
        if (cnt[i] == 0) res += r2;
        else if (cnt[i] & 1) res += r2;
        else res -= r2;
    }
    cout << (double) res * pi << endl;
}