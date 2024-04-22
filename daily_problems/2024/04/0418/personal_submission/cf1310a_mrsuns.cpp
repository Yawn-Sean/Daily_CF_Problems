void Solve() {
    int n;cin >> n;
    vector<array<int, 2>> a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i][0];
    for (int i = 1;i <= n;i++) cin >> a[i][1];
    sort(a.begin() + 1, a.end());
    multiset<int> st;ll res = 0;
    {
        ll in_sum = 0;
        int i = 1;int now = 0;
        while (st.size() || i <= n) {
            if (st.empty()) {
                now = a[i][0];st.insert(a[i][1]);in_sum += a[i][1];i++;
            }
            while (i <= n && now == a[i][0])
                st.insert(a[i][1]), in_sum += a[i][1], i++;
            auto mx = *st.rbegin();
            st.extract(mx);
            in_sum -= mx;
            res += in_sum;
            now++;
        }
    }
    cout << res << endl;
}
