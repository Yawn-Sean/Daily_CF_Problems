int n;

bool check(int x) {
    // x是2的倍数
    return (x & (x - 1)) == 0;
}
void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> cnt(maxn, 0);
    for (auto x: a) {
        while (x > 0) {
            cnt[x] += 1;
            x >>= 1;
        }
    }
    int mx = 0, prefix = 0;
    for (int i = 100000; i > 0; i --) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            prefix = i;
        }
    }
    
    int res = 0;
    for (auto& x : a) {
        // 使每一个x前缀变成prefix, 而且这个前缀一定出现了n次, 因为1就至少出现了n次
        while (x > 0 and (x % prefix > 0 or !check(x / prefix))) {
            res += 1;
            x >>= 1;
        }
    }
    for (auto& x : a) {
        x /= prefix;
        int c = 0;
        while (x > 1) {
            x >>= 1;
            c ++;
        }
        x = c;
    }
    sort(all(a));
    vector<int> l(n + 1, 0), r(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        l[i] = l[i - 1] + a[i - 1];
        r[i] = r[i - 1] + a[n - i];
    }
    
    // 枚举最后的元素
    int res1 = inf;
    for (int i = 0; i < n; i ++) {
        // 前面i个元素 后面n-i-1个元素
        int ans = (a[i] * i - l[i]) + (r[n - i - 1] - a[i] * (n - i - 1));
        res1 = min(res1, ans);
    }
    cout << res + res1 << endl;
}