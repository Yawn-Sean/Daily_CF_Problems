int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n, q; cin >> n >> q;
    LCA tree(n);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        tree.addEdge(i, p);
    }
    tree.init();

    while (q--) {
        array<int, 3> a;
        for (int i = 0; i < 3; i++) cin >> a[i];
        sort(all(a));
        int ans = 0;
        do {
            int s = a[0], t = a[1], f = a[2];
            int lca = tree.query(s, t);
            if (tree.dis(s, f) + tree.dis(t, f) == tree.dis(s, t)) setmax(ans, 1);
            else {
                if (tree.dis(s, t) + tree.dis(t, f) == tree.dis(s, f)) setmax(ans, tree.dis(t, f) + 1);
                else if (tree.dis(t, s) + tree.dis(s, f) == tree.dis(t, f)) setmax(ans, tree.dis(s, f) + 1);
                else {
                    setmax(ans, (tree.dis(s, f) + tree.dis(t, f) - tree.dis(s, t)) / 2 + 1);
                }
            }
        } while (next_permutation(all(a)));

        cout << ans << '\n';
    }

    return 0;
}
