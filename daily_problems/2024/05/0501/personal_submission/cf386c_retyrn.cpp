int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    
    vector<ll> res(27, 0);
    
    vector<int> last(26, -1);
    vector<int> pos;
    
    for (int i = 0; i < n; i ++) {
        vector<int> pos;
        last[s[i] - 'a'] = i;
        for (int j = 0; j < 26; j ++) {
            if (last[j] >= 0) pos.push_back(last[j]);
        }
        sort(all(pos));
        
        int m = sz(pos);
        for (int i = 0, cur = 0; i < m; i ++) {
            int t = pos[i] + 1 - cur;
            res[m - i] += t;
            cur += t;
        }
    }

    while (sz(res) and res.back() == 0ll) res.pop_back();
    cout << sz(res) - 1 << endl;
    for (int i = 1; i < sz(res); i ++) {
        cout << res[i] << endl;
    }
}