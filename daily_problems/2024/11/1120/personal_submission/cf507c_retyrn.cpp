int h;
ll n;

void solve() {
    cin >> h >> n;
    n += (1ll << h) - 1;
    set<ll> S;
    
    auto x = n;
    while (x >= 1) {
        S.insert(x);
        x >>= 1;
    }
    
    ll cur = 1, res = 0, layer = 0;
    int d = 0;
    while (cur != n) {
        if (d == 0) {
            // L
            ll l = cur << 1;
            if (!S.count(l)) {
                d = 1;
                res += (1ll << h - layer) - 1;
            }
            else {
                d = 1;
                layer ++;
                res += 1;
                cur = l;
            }
        }
        else {
            // R
            ll r = cur << 1 | 1;
            if (!S.count(r)) {
                d = 0;
                res += (1ll << h - layer) - 1;
            }
            else {
                d = 0;
                res += 1;
                layer ++;
                cur = r;
            }
        }
    }
    
    cout << res << endl;
}