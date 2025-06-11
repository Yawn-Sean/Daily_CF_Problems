int n;
string s;

void solve() {
    cin >> n;
    vector<string> a;
    
    for (int t = 0; t < n; t ++) {
        cin >> s;
        
        if (t == 0 or sz(s) > sz(a.back())) {
            for (auto& c : s) {
                if (c == '?') c = '0';
            }
            if (s[0] == '0') s[0] = '1';
            a.pbk(s);
            continue;
        }
        else if (sz(s) < sz(a.back())) {
            cout << "NO" << endl;
            return;
        }
        
        // 位数相等
        auto& ss = a.back();
        vector<int> stk;
        bool ok = false;
        
        for (int i = 0; i < sz(s); i ++) {
            if (isdigit(s[i])) {
                if (ss[i] == s[i]) continue;
                if (ss[i] > s[i]) {
                    while (sz(stk) and s[stk.back()] == '9') {
                        s[stk.back()] = '0';
                        stk.pop_back();
                    }
                    if (em(stk)) {
                        cout << "NO" << endl;
                        return;
                    }
                    s[stk.back()] += 1;
                }
                for (int j = i + 1; j < sz(s); j ++) {
                    if (s[j] == '?') {
                        s[j] = '0';
                    }
                }
                a.push_back(s);
                ok = true;
                break;
            }
            else {
                // ?
                s[i] = ss[i];
                stk.push_back(i);
            }
        }
        if (!ok) {
            if (s == a.back()) {
                while (sz(stk) and s[stk.back()] == '9') {
                    s[stk.back()] = '0';
                    stk.pop_back();
                }
                if (em(stk)) {
                    cout << "NO" << endl;
                    return;
                }
                s[stk.back()] += 1;
            }
            a.push_back(s);
        }
    }
    cout << "YES" << endl;
    for (auto& ss : a) {
        cout << ss << endl;
    }
}