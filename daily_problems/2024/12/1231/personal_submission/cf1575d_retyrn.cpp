int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    
    if (n == 1) {
        if (s[0] == '0' or s[0] == 'X' or s[0] == '_') {
            cout << 1 << endl;
            return;
        }
        cout << 0 << endl;
        return;
    }
    if (s[0] == '0') {
        cout << 0 << endl;
        return;
    }
    
    if (n == 2) {
        if (isdigit(s[0]) and isdigit(s[1])) {
            cout << (int)(s == "25" or s == "50" or s == "75") << endl;
            return;
        }
        if (isdigit(s[0])) {
            if (s[0] == '2' or s[0] == '7') {
                cout << (int)(s[1] == '5' or s[1] == '_' or s[1] == 'X') << endl;
                return;
            }
            if (s[0] == '5') {
                cout << (int)(s[1] == '0' or s[1] == '_' or s[1] == 'X') << endl;
                return;
            }
            cout << 0 << endl;
            return;
        }
        
        if (isdigit(s[1])) {
            if (s[1] == '5') {
                if (s[0] == '2' or s[0] == '7') {
                    cout << 1 << endl;
                    return;
                }
                if (s[0] == 'X' or s[0] == '_') {
                    cout << 2 << endl;
                    return;
                }
                cout << 0 << endl;
                return;
            }
            if (s[1] == '0') {
                cout << (int)(s[0] == '5' or s[0] == 'X' or s[0] == '_') << endl;
                return;
            }
            cout << 0 << endl;
            return;
        }
        
        if (s[0] == 'X' and s[1] == 'X') {
            cout << 0 << endl;
            return;
        }
        cout << 3 << endl;
        return;
    }
    
    reverse(all(s));
    auto dfs = [&](auto&& self, int u, int X) -> ll {
        if (u == n - 1) {
            if (s[u] == '0') return 0ll;
            if (isdigit(s[u])) return 1ll;
            if (s[u] == 'X') {
                if (X == -1) return 9ll;
                if (X == 0) return 0ll;
                else return 1ll;
            }
            return 9ll;
        }
        
        if (isdigit(s[u])) return self(self, u + 1, X);
        if (s[u] == 'X') {
            if (X >= 0) return self(self, u + 1, X);
            return self(self, u + 1, 1) * 9 + self(self, u + 1, 0);
        }
        return self(self, u + 1, X) * 10;
    };
    
    auto cal = [&](const string& st) -> ll {
        if (isdigit(s[0]) and isdigit(s[1])) {
            if (s[0] == st[0] and s[1] == st[1]) return dfs(dfs, 2, -1);
            return 0ll;
        }
        if (isdigit(s[0])) {
            if (s[0] == st[0]) {
                if (s[1] == 'X') return dfs(dfs, 2, st[1] - '0');
                return dfs(dfs, 2, -1);
            }
            return 0ll;
        }
        if (isdigit(s[1])) {
            if (s[1] == st[1]) {
                if (s[0] == 'X') return dfs(dfs, 2, st[0] - '0');
                return dfs(dfs, 2, -1);
            }
            return 0ll;
        }
        
        if (s[0] == 'X' and s[1] == 'X') {
            if (st[0] != st[1]) return 0ll;
            return dfs(dfs, 2, st[0] - '0');
        }
        
        if (s[0] == '_' and s[1] == '_') return dfs(dfs, 2, -1);
        if (s[0] == 'X') return dfs(dfs, 2, st[0] - '0');
        return dfs(dfs, 2, st[1] - '0');
    };
    
    ll res = 0;
    res += cal("00");
    res += cal("52");
    res += cal("05");
    res += cal("57");
    
    cout << res << endl;
}