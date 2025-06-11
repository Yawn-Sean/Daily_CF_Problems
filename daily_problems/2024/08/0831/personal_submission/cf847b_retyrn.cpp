int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    vector<vector<int>> b;
    for (auto x : a) {
        if (em(b) or b.back().back() > x) {
            b.push_back({x});
            continue;
        }
        int l = 0, r = sz(b) - 1;
        while (l < r) {
            auto mid = (l + r) >> 1;
            if (b[mid].back() > x) l = mid + 1;
            else r = mid;
        }
        b[l].push_back(x);
    }
    for (auto& v : b) {
        cout << v << endl;
    }
}