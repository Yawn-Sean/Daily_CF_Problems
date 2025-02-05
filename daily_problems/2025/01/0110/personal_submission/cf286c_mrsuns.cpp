void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    int m;cin >> m;
    vector<int> b(m + 1);for (int i = 1;i <= m;i++) cin >> b[i];
    for (int i = 1;i <= m;i++) {
        a[b[i]] *= -1;
    }
    vector<int> st;
    for (int i = n;i >= 1;i--) {
        if (a[i] < 0) st.push_back(a[i]);
        else {
            if (st.size() and -st.back() == a[i]) {
                st.pop_back();
            }
            else {
                a[i] *= -1;
                st.push_back(a[i]);
            }
        }
    }
    if (st.size() == 0) {
        cout << "YES\n";
        for (int i = 1;i <= n;i++) cout << a[i] << ' ';
        cout << endl;
    }
    else {
        cout << "NO\n";
    }
}
