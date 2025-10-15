
int a[N], b[N], cnta[N], cntb[N], n, m;

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnta[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        cntb[b[i]]++;
    }
    vector<int> stk;
    vector<int> res;
    for (int i = 0; i < m; i++) {
        int val = m - 1 - i;
        while (cnta[i] > 0) {
            stk.push_back(i);
            cnta[i]--;
        }
        while (cntb[val] > 0 && !stk.empty()) {
            res.push_back(val + stk.back());
            stk.pop_back();
            cntb[val]--;
        } 
    }
    vector<int> unused;
    for (int i = 0; i < m; i++) {
        while (cntb[i] > 0) {
            cntb[i]--;
            unused.push_back(i);
        }
    }

    sort(unused.begin(), unused.end());
    sort(stk.begin(), stk.end());
    assert(unused.size() == stk.size());
    for (int i = 0; i < stk.size(); i++) {
        res.push_back((unused[i] + stk[i]) % m);
    }
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    assert(res.size() == n);
    for (auto val : res) {
        cout << val << " ";
    }
}
