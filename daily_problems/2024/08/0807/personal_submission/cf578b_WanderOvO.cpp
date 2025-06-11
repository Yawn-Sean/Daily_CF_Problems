/*
k = 10, x = 8，都比较小
首先看似有一个 dp 做法，但是似乎是错的，所以考虑其他做法
假如 a 中有一个 a[i] = val，其他的 a[j] * k <= val，最优做法就是都乘给 a[i]
如果不存在这样的元素呢？感觉上应该还是都乘给一个数最好，这样能保证最高位数尽可能高，枚举乘给哪个数
*/

int T;
LL n, k, x;

void solve1() {
    cin >> n >> k >> x;
    vector<LL> a(n + 2), pre(n + 2, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] | a[i];
    }
    for (int i = n; i > 0; i--) {
        suf[i] = suf[i + 1] | a[i];
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, (pre[i - 1] | suf[i + 1] | (a[i] * (LL)pow(x, k))));
    }
    cout << res << "\n";
}   
