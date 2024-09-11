void solve() {
    int n, T;
    cin >> n >> T;
    vector<pii> question;
    map<pii, vector<int>> rev;
    for (int i = 0; i < n; i++) {
        int a, t;
        cin >> a >> t;
        question.emplace_back(t, a);
        rev[{t, a}].emplace_back(i + 1);
    }
    sort(all(question));
    int lo = -1, hi = n;
 
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        bool okay = true;
        int cnt = 0, timer = 0;
        for (auto [t, a] : question) {
            if (cnt < mid && a >= mid) {
                cnt++;
                timer += t;
            }
        }
        if (timer > T || cnt < mid) okay = false;
        if (okay) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << "\n";
    cout << lo << "\n";
    int cnt = 0;
    for (auto [t, a] : question) {
        if (cnt < lo && a >= lo) {
            cnt++;
            cout << rev[{t, a}].back() << " ";
            rev[{t, a}].pop_back();
        }
    }
}
