int n, k; 
string ss[N];
map<string, vector<int>> pos;

void meibao() {
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        int val;
        cin >> ss[i] >> val;
        pos[ss[i]].push_back(val);
    }

    for (auto &it : pos) {
        sort(it.y.begin(), it.y.end());
    }

    int res = 0, min_choose_p = INF, max_left_p = 0;
    for (auto &it : pos) {
        string s = it.x, rev_s = it.x;
        reverse(rev_s.begin(), rev_s.end());
        // cout << s << " " << rev_s << endl;
        if (s == rev_s) {
            while (it.y.size() > 1) {
                int sz = it.y.size();
                if (it.y[sz - 1] + it.y[sz - 2] > 0) {
                    res += it.y[sz - 1];
                    res += it.y[sz - 2];
                    min_choose_p = min({min_choose_p, it.y[sz - 1], it.y[sz - 2]});
                    it.y.pop_back();
                    it.y.pop_back();
                } else {
                    break;
                }
            }
            if (it.y.size() > 0) {
                max_left_p = max({max_left_p, it.y.back()});
            }
        } else {
            if (pos.count(rev_s)) {
                while (it.y.size() > 0 && pos[rev_s].size() > 0 && it.y.back() + pos[rev_s].back() > 0) {
                    res += it.y.back() + pos[rev_s].back();
                    it.y.pop_back();
                    pos[rev_s].pop_back();
                }
            }
        }
    }
    res += max(-min_choose_p, max_left_p);
    cout << res << "\n";
}
