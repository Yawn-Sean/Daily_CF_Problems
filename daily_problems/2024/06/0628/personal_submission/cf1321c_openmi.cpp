void solve() {
    int n;
    string s;
    cin >> n >> s;
    // 数组模拟双向链表
    vector<int> l(n), r(n);
    iota(all(l), -1);
    iota(all(r), 1);
    l[0] = 0, r[n-1] = n-1;
    vc<vi> v_idx(26);
    rep (i, 0, n) {
        v_idx[s[i] - 'a'].push_back(i);
    }
    int ok, ans = 0;
    vi deleted(n);
    br (i, 25, 0) {
        do {
            ok = 0;
            if (!v_idx[i].empty()) {
                for (int j: v_idx[i]) {
                    if (deleted[j]) continue;
                    if (j > 0 and s[j] - s[l[j]] == 1 or
                        j < n and s[j] - s[r[j]] == 1) {
                        int ll = l[j],  rr = r[j];
                        r[ll] = r[j], l[rr] = l[j];
                        deleted[j] = 1;
                        ok = 1;
                        ans ++;
                    }
                }
            }
        } while (ok);        
    }
    cout << ans << nl;
}
