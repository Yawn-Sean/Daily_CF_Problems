/*
不妨假设最后取了 cnt 个蘑菇，则 p[1...cnt - 1] 对应的蘑菇就废了
对于不是 0 的那 n - cnt + 1 个蘑菇，肯定是取最大的 cnt 个，这就需要 n - cnt + 1 >= cnt => cnt <= (n + 1) / 2
需要快速维护这 n - cnt + 1 个蘑菇里第 cnt 大的值
我们从大到小枚举 cnt，则相当于可选的蘑菇越来越多，相当于往一个集合中插入元素，以及查询第 cnt 大
可以离散化之后使用权值树状数组搞一下
*/

LL n, a[N], b[N], p[N];
BIT tr;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    sort(b + 1, b + n + 1);
    tr.init(n);

    int idx = n + 1;
    LL res = 0, min_cnt = n;

    auto check = [&] (int ans, int cnt) -> bool {
        return tr.query(n) - tr.query(ans - 1) >= cnt;
    };

    for (int cnt = (n + 1) / 2; cnt > 0; cnt--) {
        int left_cnt = n - cnt + 1;
        int pos = n - left_cnt + 1;
        while (idx - 1 > 0 && idx - 1 >= pos) {
            int target = lower_bound(b + 1, b + n + 1, a[p[idx - 1]]) - b;
            tr.add(target, 1);
            idx--;
        }
        int l = 1, r = n, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(mid, cnt)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (check(r, cnt)) {
            res = max(res, cnt * b[r]);
            if (res == cnt * b[r]) {
                min_cnt = min(min_cnt, (LL)cnt);
            }
        } else if (check(l, cnt)) {
            res = max(res, cnt * b[l]);
            if (res == cnt * b[l]) {
                min_cnt = min(min_cnt, (LL)cnt);
            }
        }
    }
    cout << res << " " << min_cnt << "\n";
}
