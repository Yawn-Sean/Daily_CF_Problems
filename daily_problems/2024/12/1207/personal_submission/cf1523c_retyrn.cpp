int n;

void solve() {
    cin >> n;
    vector<int> res;
    
    while (n --) {
        int x;
        cin >> x;
        if (x > 1) {
            while (sz(res) and res.back() != x - 1) res.pop_back();
            res.pop_back();
        }
        res.push_back(x);
        
        for (int i = 0; i < sz(res); i ++) {
            cout << res[i] << ".\n"[i == sz(res) - 1];
        }
    }
    
}