
// link https://codeforces.com/contest/822/submission/255172048
void solve() {
    int n, k;
    cin >> n >> k;
    int mins = inf;
    pqinit<tuple<int, int, int>, greater<>> pq1, pq2;
    map<int, int> ans;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq1.emplace(a, b, c);
    }
    while (!pq1.empty()) {
        auto [a, b, c] = pq1.top();
 
        pq1.pop();
        while (!pq2.empty() && get<0>(pq2.top()) < a) {
            auto [a1, b1, c1] = pq2.top();
            pq2.pop();
            debug("insert", a1, b1, c1);
            int kk = a1 - b1 + 1;
            if (!ans.count(kk))
                ans[kk] = c1;
            else
                ans[kk] = min(ans[kk], c1);
            debug("ans", kk, ans[kk]);
        }
        debug("check", a, b, c);
        int kk = k - (b - a + 1);
        if (ans.count(kk))
            mins = min(mins, ans[kk] + c);
        pq2.emplace(b, a, c);
    }
    if (mins == inf)
        cout << -1 << endl;
    else
        cout << mins << endl;
 
 
}
