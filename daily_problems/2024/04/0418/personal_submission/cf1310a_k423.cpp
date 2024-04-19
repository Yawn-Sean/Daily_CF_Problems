// https://codeforces.com/contest/1310/submission/257115956

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> a(n), t(n);
    for (int &x: a) cin >> x;
    for (int &x: t) cin >> x;
    map<int, multiset<int>> mp;
    map<int, i64> tot;
    for (int i = 0; i < n; ++i) {
        mp[a[i]].emplace(t[i]);
        tot[a[i]] += t[i];
    }
    int k = 0;
    i64 ans = 0;
    while (k < mp.rbegin()->first) {
        k = mp.upper_bound(k)->first;
        auto &S = mp[k];
        i64 w = tot[k];
        k--;
        do {
            k++;
            w -= *S.rbegin();
            ans += w;
            S.extract(*S.rbegin());
        } while (!mp.contains(k + 1) && !S.empty());
        if (mp.contains(k + 1) && !S.empty()) {
            tot[k + 1] += w;
            if (S.size() > mp[k + 1].size())
                mp[k + 1].swap(S);
            for (int x: S) mp[k + 1].emplace(x);
        }
    }
    cout << ans << endl;
}
