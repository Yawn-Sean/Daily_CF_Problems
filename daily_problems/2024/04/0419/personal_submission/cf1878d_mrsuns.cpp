void Solve() {
    int n, k;cin >> n >> k;
    string s;cin >> s;s = ' ' + s;
    Treap<char> tr;for (int i = 1;i <= n;i++) tr.push_back(s[i]);
    vector<array<int, 2>> a(k + 1);
    for (int i = 1;i <= k;i++) cin >> a[i][0];
    for (int i = 1;i <= k;i++) cin >> a[i][1];
    //for (auto i : tr.elements()) cout << i;cout << endl;
    int q;cin >> q;
    while (q--) {
        int x;cin >> x;
        auto ptr = upper_bound(a.begin() + 1, a.end(), array<int, 2>{ x, 1000000000 }) - a.begin() - 1;
        //cout << ptr << endl;
        int l = min(x, a[ptr][1] + a[ptr][0] - x);
        int r = max(x, a[ptr][1] + a[ptr][0] - x);
        tr.reverse(l, r);
    }
    for (auto i : tr.elements()) cout << i;cout << endl;
}
