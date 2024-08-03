// link : https://codeforces.com/contest/1912/submission/256715157
void solve() {
    int sums, k;
    cin >> sums >> k;
    vector<vector<pair<int, int>>> ans(k + 1);
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= k; i++) {
        int n;
        cin >> n;
        int su = 0;
        int mi = 0;
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            su += x;
            mi = min(mi, su);
            if (su > 0) {
                ans[i].push_back({mi, su});
//                pq.push({mi, su});
                su = 0;
                mi = 0;
            }
        }
        reverse(ans[i].begin(), ans[i].end());
        if (!ans[i].empty()) pq.push({ans[i].back().first, i});
    }
    while (!pq.empty() && sums + pq.top().first >= 0) {
        auto [mi, su] = pq.top();
        pq.pop();
        sums += ans[su].back().second;
        ans[su].pop_back();
        if (!ans[su].empty()) pq.push({ans[su].back().first, su});
    }
    cout << sums << endl;
}
