int n;

void solve() {
    cin >> n;
    vector<string> g(n);
    cin >> g;
    unordered_map<string, int> mp;
    
    const int m = 9;
    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            string s;
            for (int k = j; k < m; k ++) {
                s += g[i][k];
                mp[s] += 1;
            }
        }
    }
    
    for (int i = 0; i < n; i ++) {
        string res;
        for (int j = 0; j < m; j ++) {
            string s;
            for (int k = j; k < m; k ++) {
                s += g[i][k];
                if (!mp.count(s) or mp[s] == 0) {
                    if (em(res) or sz(res) > sz(s)) res = s;
                }
            }
        }
        cout << res << endl;
        
        for (int j = 0; j < m; j ++) {
            string s;
            for (int k = j; k < m; k ++) {
                s += g[i][k];
                mp[s] += 1;
            }
        }
        if (i + 1 < n) {
            for (int j = 0; j < m; j ++) {
                string s;
                for (int k = j; k < m; k ++) {
                    s += g[i+1][k];
                    mp[s] -= 1;
                }
            }
        }
    }
}