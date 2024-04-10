/*
看增加 a 的最小值和减少 b 的最大值哪个代价比较小，就进行哪个操作
记录当前 a 的最小值为 mn，b 的最大值为 mx
我们不真正修改 a 和 b，只看 <= mn 和 >= mx 的数有多少
可能需要离散化一下？

我们需要在 [mn, mx](mn <= mx) 之间找一个分界点 p，然后让 a 中所有数 >= p，b 中所有数 <= p
如果 [mn, mx] 这个区间不是很大，则可以 a 和 b 先排序，然后枚举 p in [mn, mx]
利用二分 + 前缀和快速求出需要进行多少操作
我们能否断言 a 和 b 中原本就出现的数之一就是最优的 p 呢？如果真，只需要枚举至多 O(n) 个数即可
*/

int T;
LL a[N], b[N], n, m, sa[N], sb[N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++) {
        sa[i] = sa[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++) {
        sb[i] = sb[i - 1] + b[i];
    }
    
    LL mn = a[1], mx = b[m];
    if (mn >= mx) {
        cout << "0\n";
        return;
    }
    
    vector<LL> p;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= mx && a[i] >= mn) {
            p.pb(a[i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (b[i] <= mx && b[i] >= mn) {
            p.pb(b[i]);
        } 
    }
    
    LL res = INF;
    for (auto &goal : p) {
        LL ans = 0;
        // 第一个 <= goal 的元素下标
        int pos1 = upper_bound(a + 1, a + n + 1, goal) - a - 1;
        // 第一个 > goal 的元素下标
        int pos2 = upper_bound(b + 1, b + m + 1, goal) - b;
        ans += (pos1 * goal - sa[pos1]);
        ans += ((sb[m] - sb[pos2 - 1]) - (m - pos2 + 1) * goal);
        res = min(res, ans);
    }
    cout << res << "\n";
}                                                                                                                             
