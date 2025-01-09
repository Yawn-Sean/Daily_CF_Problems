void Solve() {
    int n, q;cin >> n >> q;
    vector<vector<int>> pos(n + 1);
    vector<int> id(n + 1);
    vector<int> eve(1);
    int res = 0;
    int lst = 0;
    while (q--) {
        int op, x;cin >> op >> x;
        if (op == 1) {
            pos[x].push_back(eve.size());
            eve.push_back(x);
            res++;
        }
        else if (op == 2) {
            res -= pos[x].size() - id[x];
            id[x] = pos[x].size();
        }
        else {
            if (x <= lst);
            else {
                for (int i = lst + 1;i <= x;i++) {
                    int u = eve[i];
                    auto j = lower_bound(pos[u].begin(), pos[u].end(), i) - pos[u].begin();
                    if (id[u] <= j) {
                        res -= 1;
                        id[u]++;
                    }
                }
                lst = x;
            }
        }
        cout << res << endl;
    }
}
