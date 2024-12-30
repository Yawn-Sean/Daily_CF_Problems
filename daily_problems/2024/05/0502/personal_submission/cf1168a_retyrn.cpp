int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    
    auto check = [&](int x) {
        int last = 0;
        for (int i = 0; i < n; i ++) {
            if (a[i] <= last) {
                if (last - a[i] > x) return false;
            }
            else {
                // 尝试变成a[i-1]
                int need = m + last - a[i];
                if (need > x) last = a[i];
            }
        }
        return true;
    };
    
    // 二分贪心
    int l = 0, r = m;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}