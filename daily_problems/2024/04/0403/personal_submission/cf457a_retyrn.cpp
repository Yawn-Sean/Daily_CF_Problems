int n;
using pll = pair<ll, ll>;

void solve() {
    string s;
    cin >> s;
    n = sz(s);
    vector<ll> cnt(100010, 0);
    for (int i = 0; i < n; i ++) {
        if (s[i] == '1') cnt[n - i] += 1;
    }
    cin >> s;
    n = sz(s);
    for (int i = 0; i < n; i ++) {
        if (s[i] == '1') cnt[n - i] -= 1;
    }
    
    for (int i = 100000; i > 1; i --) {
        if (cnt[i] > 2e18) {
            cout << ">" << endl;
            return;
        }
        if (cnt[i] < -2e18) {
            cout << '<' << endl;
            return;
        }
        if (cnt[i] != 0) {
            cnt[i - 1] += cnt[i];
            cnt[i - 2] += cnt[i];
            cnt[i] = 0;
        }
    }
    
    pll a = mpr(cnt[1], cnt[0]);
    
    // a.fi 根号5 + 1  +  a.se 2
    if (a.fi == 0 and a.se == 0) {
        cout << '=' << endl;
        return;
    }
    if (a.fi >= 0 and a.se >= 0) {
        cout << '>' << endl;
        return;
    }
    if (a.fi <= 0 and a.se <= 0) {
        cout << '<' << endl;
        return;
    }
    
    int sgn = 1;
    if (a.fi < 0) a.fi = -a.fi, sgn = -1;
    else a.se = -a.se;
    a.se = a.se * 2 - a.fi;
    
    // a.fi 根号5 + a.se 1
    if (5 * a.fi * a.fi > a.se * a.se) {
        cout << (sgn > 0 ? '>' : '<') << endl;
    }
    else {
        cout << (sgn > 0 ? '<' : '>') << endl;
    }
}