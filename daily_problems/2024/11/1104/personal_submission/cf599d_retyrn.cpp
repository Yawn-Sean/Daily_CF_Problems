ll x;
using pll = pair<ll, ll>;

void solve() {
    cin >> x;
    vector<pll> res;
    ll sum = 0;
    for (int a = 0; a < 2000000; a ++) {
        sum += (ll)a * a;
        ll t1 = x - sum + (ll)a * (1 + a) / 2 * a;
        ll t2 = (ll)a * a - (ll)a * (1 + a) / 2;
        if (t1 <= 0 or t2 <= 0) continue;
        if (t1 % t2 == 0) {
            auto b = t1 / t2;
            if (a <= b) {
                res.push_back(mpr(a - 1, b - 1));
            }
        }
    }
    int m = sz(res);
    for (int i = m - 1; i >= 0; i --) {
        if (res[i].fi == res[i].se) continue;
        res.emplace_back(res[i].se, res[i].fi);
    }
    
    cout << sz(res) << endl;
    for (auto [x, y] : res) {
        cout << x << ' ' << y << endl;
    }
}