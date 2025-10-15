void Solve() {
    int n, L, x, y;cin >> n >> L >> x >> y;
    vector<int> a(n + 1);
    set<int> exist;
    for (int i = 1;i <= n;i++) cin >> a[i], exist.insert(a[i]);
    set<int> A, B;
    for (int i = 1;i <= n;i++) {
        int t = a[i] - x;
        if (t >= 0) {
            A.insert(t);
        }
        t = a[i] + x;
        if (t <= L) {
            A.insert(t);
        }
    }
    for (int i = 1;i <= n;i++) {
        int t = a[i] - y;
        if (t >= 0) {
            B.insert(t);
        }
        t = a[i] + y;
        if (t <= L) {
            B.insert(t);
        }
    }
    for (auto i : A) {
        if (exist.count(i)) {
            for (auto j : B) {
                if (exist.count(j)) {
                    cout << 0 << endl;
                    return;
                }
            }
            cout << 1 << endl;
            cout << *B.begin() << endl;
            return;
        }
    }
    for (auto j : B) {
        if (exist.count(j)) {
            cout << 1 << endl;
            cout << *A.begin() << endl;
            return;
        }
    }
    for (auto i : A) {
        if (B.count(i)) {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << *A.begin() << ' ' << *B.begin() << endl;
}
