int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    
    vector<vector<int>> a;
    vector<vector<int>> pos(2);
    
    for (int i = 0; i < n; i ++) {
        if (s[i] == '0') {
            // 找1结尾的
            if (em(pos[1])) {
                a.push_back({i + 1});
                pos[0].push_back(sz(a) - 1);
            }
            else {
                auto idx = pos[1].back();
                a[idx].push_back(i + 1);
                pos[1].pop_back();
                pos[0].push_back(idx);
            }
        }
        else {
            if (em(pos[0])) {
                cout << -1 << endl;
                return;
            }
            auto idx = pos[0].back();
            pos[0].pop_back();
            a[idx].push_back(i + 1);
            pos[1].push_back(idx);
        }
    }
    
    if (sz(pos[1])) {
        cout << -1 << endl;
        return;
    }
    
    cout << sz(a) << endl;
    for (auto& v : a) {
        cout << sz(v) << ' ' << v << endl;
    }
}