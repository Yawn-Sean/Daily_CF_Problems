void Solve() {
    int n, q;cin >> n >> q;
    DSU d(n + 1);
    set<int> st;
    for (int i = 2;i <= n;i++) st.insert(i);
    while (q--) {
        int op, x, y;cin >> op >> x >> y;
        if (op == 1) {
            d.merge(x, y);
        }
        else if (op == 2) {
            auto itl = st.lower_bound(x + 1);
            auto itr = st.upper_bound(y);
            set<int> era;
            for (auto it = itl;it != itr;it++) {
                d.merge((*it) - 1, *it);
                era.insert(*it);
            }
            for (auto i : era) st.erase(i);
        }
        else {
            if (d.same(x, y)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
