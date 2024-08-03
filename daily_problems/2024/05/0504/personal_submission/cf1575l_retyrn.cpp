int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    // 先找到每个数要合法的需要向前移动的个数
    vector<pii> z;
    for (int i = 0; i < n; i ++) {
        int val;
        if (i + 1 < a[i]) val = -1;
        else val = i + 1 - a[i];
        if (val >= 0) {
            z.emplace_back(val, a[i]);
        }
    }
    // zip(val, a)的LIS 满足第一位不递减 第二位严格递增
    sort(all(z));
    
    vector<int> q(n + 1, 0);
    q[0] = -inf;
    
    int len = 0;
    
    for (int i = 0; i < sz(z); i ++) {
        int val = z[i].se;
        int l = 0, r = len;
        while (l < r) {
            auto mid = (l + r + 1) >> 1;
            if (q[mid] < val) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = val;
    }
    cout << len << endl;
}