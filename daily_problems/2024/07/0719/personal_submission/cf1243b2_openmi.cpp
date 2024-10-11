void solve() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    map<char, priority_queue<int, vector<int>, greater<>>> spq, tpq;
    map<char, set<int>> lazy_del;
    for (int i = 0; i < n; ++i) {
        spq[s[i]].push(i);
        tpq[t[i]].push(i);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        char cs = s[i], ct = t[i];
        if (cs != ct) {
            while (!spq[cs].empty() and spq[cs].top() <= i) spq[cs].pop();
            while (!spq[cs].empty() and lazy_del[cs].count(spq[cs].top())) lazy_del[cs].erase(lazy_del[cs].find(spq[cs].top())), spq[cs].pop();
            while (!tpq[cs].empty() and tpq[cs].top() <= i) tpq[cs].pop();
            if (spq[cs].empty() and tpq[cs].empty()) break;
            if (!spq[cs].empty()) {
                int si = spq[cs].top(); spq[cs].pop();
                spq[ct].push(si);
                swap(s[si], t[i]);
                ans.emplace_back(si, i);
            } else {
                int ti = tpq[cs].top(); tpq[cs].pop();
                spq[ct].push(ti);
                lazy_del[s[ti]].insert(ti);
                tpq[s[ti]].push(ti);
                ans.emplace_back(ti, ti);
                ans.emplace_back(ti, i);
                swap(t[ti], s[ti]);
                swap(s[ti], t[i]);
            }
        }
    }
    if (s == t) {
        p(1);
        cout << ans.size() << nl;
        for (auto&[a, b]: ans) cout << a + 1 << ' ' << b + 1 << nl;
    } else {
        p(0);
    }
    
}
