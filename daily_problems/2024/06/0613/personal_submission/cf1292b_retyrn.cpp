int n;
ll x0, y0, ax, ay, bx, by;
using pll = pair<ll, ll>;
ll x, y, t;

void solve() {
    cin >> x0 >> y0;
    cin >> ax >> ay >> bx >> by;
    cin >> x >> y >> t;
    
    // 每次只会往右上走 点数不会特别多
    vector<pll> v;
    const ll m = 2e16;
    while (x0 <= m and y0 <= m) {
        v.push_back(mpr(x0, y0));
        x0 = x0 * ax + bx;
        y0 = y0 * ay + by;
    }
    // 枚举开始位置
    int res = 0;
    for (int i = 0; i < sz(v); i ++) {
        ll cost1 = abs(x - v[i].fi) + abs(y - v[i].se);
        if (cost1 > t) continue;
        for (int j = i; j < sz(v); j ++) {
            ll cost2 = (v[j].fi - v[i].fi) + (v[j].se - v[i].se);
            if (cost1 + cost2 <= t) res = max(res, j - i + 1);
            else break;
        }
        for (int j = i; j >= 0; j --) {
            ll cost2 = (v[i].fi - v[j].fi) + (v[i].se - v[j].se);
            if (cost1 + cost2 <= t) res = max(res, i - j + 1);
            else break;
        }
    }
    cout << res << endl;
}