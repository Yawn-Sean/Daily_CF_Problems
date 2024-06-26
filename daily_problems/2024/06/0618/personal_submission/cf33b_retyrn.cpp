int n;
string s, t;

void solve() {
    cin >> s >> t;
    n = sz(s);
    
    if (sz(s) != sz(t)) {
        cout << -1 << endl;
        return;
    }
    
    int m;
    cin >> m;
    vector<vector<int>> d(26, vector<int>(26, inf));
    for (int i = 0; i < 26; i ++) {
        d[i][i] = 0;
    }
    while (m --) {
        string s1, s2;
        int val;
        cin >> s1 >> s2 >> val;
        int u = (s1[0] - 'a'), v = (s2[0] - 'a');
        d[u][v] = min(d[u][v], val);
    }
    for (int k = 0; k < 26; k ++) {
        for (int i = 0; i < 26; i ++) {
            for (int j = 0; j < 26; j ++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll res = 0;
    string ss;
    for (int i = 0; i < n; i ++) {
        int u = (s[i] - 'a'), v = (t[i] - 'a');
        int mn = inf, aim = 0;
        for (int j = 0; j < 26; j ++) {
            if (d[u][j] + d[v][j] < mn) {
                mn = d[u][j] + d[v][j];
                aim = j;
            }
        }
        if (mn == inf) {
            cout << -1 << endl;
            return;
        }
        res += mn;
        ss += 'a' + aim;
    }
    cout << res << endl;
    cout << ss << endl;
}