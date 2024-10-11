int n;
using al3 = array<ll, 3>;
using pll = pair<ll, ll>;

int cal(vector<int>& v, int a, int b, int c, int d) {
    queue<al3> q;
    q.push({(ll)c, (ll)d, 0ll});
    set<pll> S;
    
    while (!em(q)) {
        auto t = q.front();
        q.pop();
        ll x = t[0], y = t[1], c = t[2];
        if (x >= a and y >= b) {
            return c;
        }
        if (c >= n) continue;
        if (x < a) {
            ll nx = x * v[c], ny = y;
            if (!S.count(mpr(nx, ny))) {
                q.push({nx, ny, c + 1});
                S.insert(mpr(nx, ny));
            }
        }
        if (y < b) {
            ll nx = x, ny = y * v[c];
            if (!S.count(mpr(nx, ny))) {
                q.push({nx, ny, c + 1});
                S.insert(mpr(nx, ny));
            } 
        }
    }
    return inf;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d >> n;
    vector<int> v(n);
    cin >> v;
    sort(all(v), greater<int>());
    while (sz(v) and v.back() == 1) v.pop_back();
    n = min(sz(v), 34);
    
    int res = min(cal(v, a, b, c, d), cal(v, b, a, c, d));
    
    cout << (res == inf ? -1 : res) << endl;
}