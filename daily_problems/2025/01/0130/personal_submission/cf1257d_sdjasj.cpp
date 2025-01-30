void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<vector<int>> nums1(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> nums1[i][0] >> nums1[i][1];
    }
    sort(nums1.begin(), nums1.end(), [&](auto& a, auto& b) -> bool {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] > b[0];
    });
    vector<vector<int>> stk;
    for (auto& v : nums1) {
        if (stk.empty() || stk.back()[1] < v[1]) {
            stk.push_back(v);
        }
    }
    int ans = 0;
    auto find = [&](int x) -> int {
        int l = 0, r = stk.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (stk[mid][0] >= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return r;
    };
    for (int i = 0; i < n; ) {
        int id = stk.size() - 1;
        if (stk[0][0] < a[i]) {
            cout << -1 << endl;
            return;
        }
        int cnt = 0;
        while (i < n && cnt < stk[id][1]) {
            if (stk[id][0] < a[i]) {
                id = find(a[i]);
                if (stk[id][0] < a[i]) {
                    cout << -1 << endl;
                    return;
                }
                if (cnt >= stk[id][1]) {
                    break;
                }
            }
            cnt++;
            i++;
        }
        ans++;
    }
    cout << ans << endl;
}
