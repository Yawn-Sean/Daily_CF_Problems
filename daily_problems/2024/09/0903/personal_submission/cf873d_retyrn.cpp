int n, k;

void solve() {
    cin >> n >> k;
    // 找到大于等于k的第一个长度
    vector<int> a(n + 1);
    a[0] = 0, a[1] = 1;
    for (int i = 2; i <= n; i ++) {
        a[i] = a[i / 2] + a[i - i / 2] + 1;
    }
    if (a[n] < k or k % 2 == 0) {
        cout << -1 << endl;
        return;
    }
    vector<int> res(n);
    
    auto dfs = [&](auto&& dfs, int l, int r, int val, int left) -> void {
        if (left == 1) {
            for (int i = l; i < r; i ++) {
                res[i] = val + (i - l);
            }
            return;
        }
        
        int mid = (l + r) >> 1, len = r - l, len1 = mid - l;
        if (left - 2 <= a[len1]) {
            // 右边顺序
            for (int i = 0; i < len - len1; i ++) {
                res[mid + i] = val + i;
            }
            dfs(dfs, l, mid, val + len - len1, left - 2);
        }
        else {
            // 左边逆序
            for (int i = 0; i < len1; i ++) {
                res[mid - 1 - i] = val + i;
            }
            dfs(dfs, mid, r, val + len1, left - 1 - a[len1]);
        }
    };
    
    dfs(dfs, 0, n, 1, k);
    
    cout << res << endl;
}