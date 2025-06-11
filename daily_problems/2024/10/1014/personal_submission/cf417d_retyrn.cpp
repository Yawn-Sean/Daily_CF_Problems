int n, m, b;
using ai3 = array<int, 3>;

void solve() {
    cin >> n >> m >> b;
    vector<ai3> a(n); // [monitor, st, money]
    for (int i = 0; i < n; i ++) {
        int x, k, t;
        cin >> x >> k >> t;
        int st = 0;
        for (int j = 0; j < t; j ++) {
            int y;
            cin >> y;
            y --;
            st |= (1 << y);
        }
        a[i][0] = k, a[i][1] = st, a[i][2] = x;
    }
    
    sort(all(a));
    ll res = inf2;
    
    vector<ll> f(1 << m, inf2);
    f[0] = 0ll;
    
    for (int i = 0; i < n; i ++) {
        ll need = (ll)b * a[i][0];
        for (int j = (1 << m) - 1; j >= 0; j --) {
            if (f[j] == inf2) continue;
            int nj = j | a[i][1];
            int cost = a[i][2];
            chmin(f[nj], f[j] + cost);
        }
        chmin(res, f[(1 << m)-1] + need);
    }
    
    cout <<(res == inf2 ? -1 : res) << endl;
}