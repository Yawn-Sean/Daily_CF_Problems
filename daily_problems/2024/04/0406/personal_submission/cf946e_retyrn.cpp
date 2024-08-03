int n;
string s;

bool check() {
    if (s[0] != '1') return false;
    for (int i = 1; i < n - 1; i ++) {
        if (s[i] != '0') return false;
    }
    return s.back() <= '1';
}

void solve() {
    cin >> s;
    n = sz(s);
    
    // 特判1000 1001
    if (check()) {
        string res(n - 2, '9');
        cout << res << endl;
        return;
    }

    int st = 0;
    for (auto c : s) {
        int u = c - '0';
        st ^= (1 << u);
    }
    
    // 一定可以保持相同长度 最坏不过是1001
    for (int i = n - 1; i >= 0; i --) {
        st ^= (1 << (s[i] - '0'));
        for (int j = s[i] - '0' - 1; j >= 0; j --) {
            int ns = st ^ (1 << j);
            int cnt = __builtin_popcount(ns);
            if (cnt <= n - i - 1) {
                s[i] = j + '0';
                for (int j = i + 1; j + cnt < n; j ++) s[j] = '9';
                int idx = n - cnt;
                for (int j = 9; j >= 0; j --) {
                    if (ns >> j & 1) {
                        s[idx ++] = '0' + j;
                    }
                }
                cout << s << endl;
                return;
            }
        }       
    }
}