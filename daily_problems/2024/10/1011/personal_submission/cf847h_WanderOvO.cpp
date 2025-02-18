/*
如果 a[i] 是峰值，那么 a[i] 至少是多少？a[i] = max(a[j] + abs(i - j))
拆绝对值，对于左边的就是 max(a[j] - j) + i，右边的就是 max(a[j] + j) - i
如何快速计算总共需要加多少？
先把直接单调递减的代价枚举算出来
最大值从 i 位置变成 i + 1 位置时
- 先减去 a[i] 之前加的，然后 a[i] 加上左边的贡献
- a[i + 1] 减去右边的贡献，然后加上左右两边的贡献
*/

LL a[N], n, pre[N], suf[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pre[0] = -INFLL;
    suf[n + 1] = -INFLL;
    for (int i = 1; i <= n; i++) {
        pre[i] = max(pre[i - 1], a[i] - i);
    }
    for (int i = n; i > 0; i--) {
        suf[i] = max(suf[i + 1], a[i] + i);
    }
    LL base_cost = 0;
    for (int i = 1; i <= n; i++) {
        LL target = max(a[i], suf[i + 1] - i);
        base_cost += max(0LL, target - a[i]);
    }
    // cout << base_cost << "\n";
    LL res = base_cost;
    for (int i = 2; i <= n; i++) {
        LL old_target = max({pre[i - 2] + i - 1, suf[i] - i + 1, a[i - 1]});
        LL old_add = max(0LL, old_target - a[i - 1]);
        base_cost -= old_add;
        LL new_target = max(pre[i - 2] + i - 1, a[i - 1]);
        LL new_add = max(0LL, new_target - a[i - 1]);
        base_cost += new_add;

        old_target = max(suf[i + 1] - i, a[i]);
        old_add = max(0LL, old_target - a[i]);
        base_cost -= old_add;
        new_target = max({pre[i - 1] + i, suf[i + 1] - i, a[i]});
        new_add = max(0LL, new_target - a[i]);
        base_cost += new_add;

        // cout << base_cost << "\n";
        res = min(res, base_cost);
    }
    cout << res << "\n";
}            
