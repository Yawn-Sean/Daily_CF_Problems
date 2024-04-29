void Solve() {
    int a, b;cin >> a >> b;
    int l = 1, r = 1e6;
    while (l <= r) {
        int mid = l + r >> 1;
        if (mid * (mid + 1) / 2 <= a + b) l = mid + 1;
        else r = mid - 1;
    }
    int k = l - 1;
    basic_string<int> resa, resb;
    for (int i = k;i >= 1;i--) {
        if (a >= i) resa += i, a -= i;
        else resb += i;
    }
    cout << resa.size() << endl;
    for (auto i : resa) cout << i << " ";cout << endl;
    cout << resb.size() << endl;
    for (auto i : resb) cout << i << " ";cout << endl;
}
