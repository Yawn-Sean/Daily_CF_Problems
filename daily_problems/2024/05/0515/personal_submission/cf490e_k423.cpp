// https://codeforces.com/contest/490/submission/261024697

/* 我永远喜欢爱莉希雅♪ */
bool f(string &p, string &s) {
    if (p.size() > s.size()) return false;
    function<bool(int, bool)> dfs = [&](int i, bool is_limit) -> bool {
        if (i < 0) return !is_limit;
        int pre = i < p.size() ? p[i] - '0' : 0;
        if (is_limit) {
            if (s[i] == '?') {
                if (i + 1 < s.size() || pre) {
                    s[i] = '0' + pre;
                    if (dfs(i - 1, true)) return true;
                    s[i] = '?';
                }
                if (pre < 9) {
                    s[i] = '0' + pre + 1;
                    return dfs(i - 1, false);
                }
                return false;
            } else {
                if (s[i] - '0' >= pre) {
                    return dfs(i - 1, s[i] - '0' == pre);
                } else {
                    return false;
                }
            }
        } else {
            if (s[i] == '?') s[i] = '0';
            return dfs(i - 1, false);
        }
    };
    return dfs(max(p.size(), s.size()) - 1, true);
}

void elysia() {
    int n;
    cin >> n;
    string p = "0";
    vector<string> ans;
    while (n--) {
        string s;
        cin >> s;
        ranges::reverse(p), ranges::reverse(s);
        if (!f(p, s)) return NO();
        ranges::reverse(p), ranges::reverse(s);
        ans.emplace_back(s);
        assert(p.size() < s.size() || p < s);
        p.swap(s);
    }
    YES();
    for (string &s: ans) cout << s << endl;
}
