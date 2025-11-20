/*
还是考虑 dp 吧
dp[i][0/1] 表示第 i 个位置用 a[i]/b[i] 的 LIS 长度
除了 LIS 长度，我们似乎还要维护达到这个 LIS 长度时的末尾元素最小值
我们好像还是设以 a[i]/b[i] 结尾比较好，这样就不用多维护这个东西了
考虑 dp[i][0]，我们关心前面选的任何 a[j]/b[j] < a[i]
我们维护树状数组，记录以值 val 结尾的 LIS 是多长
然后只需要根据 a[i] 查一个前缀 max，+ 1 就是 dp[i][0] 了
注意，事实上要维护两棵树状数组，一棵是 dp[i][0] 的，另一个是 dp[i][1] 的
*/


struct Fenwick {
    int tr[N], n;
    
    int lowbit(int x) {
        return x & -x;
    }    
    
    void modify(int pos, int val) {
        while (pos <= n) {
            tr[pos] = max(tr[pos], val);
            pos += lowbit(pos);
        }
    }
    
    int query(int pos) {
        int res = 0;
        while (pos) {
            res = max(res, tr[pos]);
            pos -= lowbit(pos);
        }
        return res;
    }
};

Fenwick fen[2];
int n, a[N], b[N], c[N];
int dp[N][2];

void solve() {   
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i + n] = b[i];
    }
    
    sort(c + 1, c + 2 * n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(c + 1, c + 2 * n + 1, a[i]) - c;
        b[i] = lower_bound(c + 1, c + 2 * n + 1, b[i]) - c;
    }
    
    fen[0].n = 2 * n;
    fen[1].n = 2 * n;
    
    for (int i = 1; i <= n; i++) {
        int p1 = a[i] - 1;
        dp[i][0] = max(dp[i][0], fen[0].query(p1) + 1);
        dp[i][0] = max(dp[i][0], fen[1].query(p1) + 1);
        int p2 = b[i] - 1;
        dp[i][1] = max(dp[i][1], fen[0].query(p2) + 1);
        dp[i][1] = max(dp[i][1], fen[1].query(p2) + 1);
        fen[0].modify(a[i], dp[i][0]);
        fen[1].modify(b[i], dp[i][1]);
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max({res, dp[i][0], dp[i][1]});
    }
    cout << res;
}
