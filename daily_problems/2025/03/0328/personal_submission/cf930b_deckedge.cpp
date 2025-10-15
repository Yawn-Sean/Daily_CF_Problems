
void solve() {
    string s;
    cin >> s;
    int n = s.size(), tot = 0;;
    unordered_map<char, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]].emplace_back(i);
    }
    for (auto itor : mp) {
        vector<int> list = itor.se;
        if (list.empty()) {
            continue;
        }
        int mx = 0;
        for (int i = 1; i < n; i++) {
            int cnt = 0;
            unordered_map<char, int> cur;
            for (int x : list) {
                char c = s[(x + i) % n];
                cur[c]++;
            }
            for (auto vec : cur) {
                if (vec.se == 1) {
                    cnt++;
                }
            }
            if (cnt > mx) {
                mx = cnt;
            }
        }
        tot += mx;
    }
    double res = (double)tot / n;
    cout << fixed << setprecision(15) << res << '\n';    
}

