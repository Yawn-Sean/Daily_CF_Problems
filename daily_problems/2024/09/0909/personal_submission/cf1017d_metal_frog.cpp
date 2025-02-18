void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    } 
    unordered_map<string, int> maskCnt;
    unordered_map<string, vector<pii>> query;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        maskCnt[s]++;
    }
    for (int i = 0; i < q; i++) {
        int k;
        string s;
        cin >> s >> k;
        query[s].emplace_back(k, i);
    }
    vector<int> ans(q);
    for (auto& [qmask, que] : query) {
        sort(all(que));
        map<int, int> wuCnt;
        for (auto& [mask, cnt] : maskCnt) {
            int wu = 0;
            for (int i = 0; i < n; i++) {
                if (qmask[i] == mask[i]) wu += weight[i];
            }
            wuCnt[wu] += cnt;
        }
        auto it = wuCnt.begin();
        int sum = 0;
        for (int i = 0; i < sz(que); i++) {
            if (it == wuCnt.end() || it->first > que[i].first) {
                ans[que[i].second] = sum;
                continue;
            } 
            while (it != wuCnt.end() && it->first <= que[i].first) {
                sum += it->second;
                it++;
            }
            ans[que[i].second] = sum;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}
