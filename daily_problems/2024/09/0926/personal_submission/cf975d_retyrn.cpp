int n, a, b;
using ai3 = array<int, 3>;

void solve() {
    cin >> n >> a >> b;
    map<ll, int> mp1;
    map<pii, int> mp2;
    ll res = 0;
    for (int i = 0; i < n; i ++) {
        int x, vx, vy;
        cin >> x >> vx >> vy;
        auto t = -(ll)a * vx + vy;
        res += mp1[t] - mp2[mpr(vx, vy)];
        mp1[t] += 1;
        mp2[mpr(vx, vy)] += 1;
    }
    cout << res * 2 << endl;
}