int n, m, a, b;
using ld = long double;

void solve() {
    cin >> n >> m >> a >> b;
    
    vector<int> y1(n), y2(m), l(m);
    cin >> y1 >> y2 >> l;
    
    auto cal = [&](int x, int y) -> ld {
        return sqrtl((ll)a * a + (ll)y1[x] * y1[x]) + sqrtl((ll)(a - b) * (a - b) + (ll)(y1[x] - y2[y]) * (y1[x] - y2[y])) + l[y];
    };
    
    ld mn = 1e18;
    int who1 = -1, who2 = -1;
    int cur = 0;
    
    for (int i = 0; i < m; i ++) {
        while (cur + 1 < n and cal(cur, i) > cal(cur + 1, i)) cur ++;
        
        if (chmin(mn, cal(cur, i))) {
            who1 = cur, who2 = i;
        }
    }
    
    cout << who1 + 1 << ' ' << who2 + 1 << endl;
}