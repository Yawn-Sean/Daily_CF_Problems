int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> b;
    // b是a的补集
    for (int i = 0, j = 1; i < n; i ++) {
        while (j < a[i]) {
            b.push_back(j ++);
        }
        if (j == a[i]) j ++;
        if (i == n - 1) {
            while (j <= n * 2) {
                b.push_back(j ++);
            }
        }
    }
    
    // 左边界
    // 至多x对取最小值 保证n-x对最大值是可以的
    int mn = n, mx = 0;
    
    {
        int l = 0, r = n;
        while (l < r) {
            auto mid = (l + r) >> 1;
            bool ok = true;
            for (int i = mid; i < n and ok; i ++) {
                if (a[i] < b[i - mid]) ok = false;
            }
            if (ok) r = mid;
            else l = mid + 1;
        }
        mn = l;
    }
    
    // 至多n-x对取最大值 保证x对最小值是可以的
    {
        int l = 0, r = n;
        while (l < r) {
            auto mid = (l + r + 1) >> 1;
            bool ok = true;
            for (int i = 0; i < mid and ok; i ++) {
                if (a[i] > b[n - mid + i]) ok = false;
            }
            if (ok) l = mid;
            else r = mid - 1;
        }
        mx = r;
    }
    
    cout << max(0, mx - mn + 1) << endl;

}