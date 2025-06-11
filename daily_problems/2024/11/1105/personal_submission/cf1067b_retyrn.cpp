int n, k;

void solve() {
    cin >> n >> k;
    vector<vector<int>> g(n);
    
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    vector<int> del(n, false);
    set<int> q;
    
    for (int i = 0; i < n; i ++) {
        if (sz(g[i]) == 1) q.insert(i);
    }
    
    for (int i = 0; i < k; i ++) {
        if (em(q)) {
            cout << "No" << endl;
            return;
        }
        set<int> root3;
        set<int> nxt;
        for (auto x : q) {
            int root = -1;
            for (auto y : g[x]) {
                if (!del[y]) {
                    if (root != -1) {
                        cout << "No" << endl;
                        return;
                    }
                    root = y;
                }
            }
            if (root == -1 or sz(g[root]) < 3) {
                cout << "No" << endl;
                return;
            }
            if (sz(g[root]) == 3) {
                root3.insert(root);
            }
            del[x] = true;
            nxt.insert(root);
        }
        if (sz(nxt) > 1) {
            if (sz(root3)) {
                cout << "No" << endl;
                return;
            }
        }
        if (sz(nxt) == 1) {
            if (sz(root3) > 1) {
                cout << "No" << endl;
                return;
            }
        }
        q = move(nxt);
    }
    // 只剩下最后一个点
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        if (!del[i]) cnt ++;
    }
    cout << (cnt == 1 ? "Yes" : "No") << endl;
}