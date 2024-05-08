const int mod = 998244353, INF = 1 << 30;
using a2 = array<int, 2>;
int n;
a2 a[N];
a2 pre[N], suf[N];


void solve() {
    // 一种特殊的前缀和
    // https://atcoder.jp/contests/abc125/tasks/abc125_c 也是类似
    // 算出前后缀 然后枚举扣去的值
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i][0] >> a[i][1];
    pre[0] = {0, INF};
    for (int i = 1; i <= n; i ++) {
        if (pre[i - 1] == a2({INF, 0})) {
            pre[i] = pre[i - 1];
            continue;
        }
        int l = max(a[i][0], pre[i - 1][0]);
        int r = min(a[i][1], pre[i - 1][1]);
        if (l > r) {
            pre[i] = {INF, 0};
        } else {
            pre[i] = {l, r};
        }
    }
    suf[n + 1] = {0, INF};
    for (int i = n; i >= 1; i --) {
        if (suf[i + 1] == a2({INF, 0})) {
            suf[i] = suf[i + 1];
            continue;
        }
        int l = max(a[i][0], suf[i + 1][0]);
        int r = min(a[i][1], suf[i + 1][1]);
        if (l > r) {
            suf[i] = {INF, 0};
        } else {
            suf[i] = {l, r};
        }
    }
    // 扣去
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int l = max(pre[i - 1][0], suf[i + 1][0]);
        int r = min(pre[i - 1][1], suf[i + 1][1]);
        if (l <= r) ans = max(ans, r - l);
    }
    cout << ans << endl;
}
