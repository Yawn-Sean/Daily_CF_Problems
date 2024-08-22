const int MOD = 998244353;
const int N = 2e5 + 10;
vector<int> vis(N);

void Solve() {
    array<int, 2> n;
    int k, q;cin >> n[0] >> n[1] >> k >> q;
    vector x(2, vector<int>(q + 1));
    for (int i = 1;i <= q;i++) {
        cin >> x[0][i] >> x[1][i];
    }
    int res = 1;
    auto ck = [&](int op, vector<int>& a) {
        set<int> st, era;
        for (int i = q;i >= 1;i--) {
            int u = x[op][i];
            if (!vis[u]) {
                vis[u] = 1;
                era.insert(u);
                if (st.size() != n[op ^ 1]) a[i] = 1;
            }
            st.insert(x[op ^ 1][i]);
        }
        for (auto i : era) vis[i] = 0;
        };
    vector<int> a(q + 1), b(q + 1);
    ck(0, a);
    ck(1, b);
    for (int i = 1;i <= q;i++) {
        int c = a[i] | b[i];
        res = res * (c ? k : 1) % MOD;
    }
    cout << res << endl;
}
