/*
如果没有修改，怎么做？好像可以离线做

给定操作历史和查询结果，重新构建数组
查的是最大值，这是否意味着很多值可以任意小？
如何判断矛盾？
n, m = 5000，不大

羊的提示：n * m 都没有超过限制，所以对于每个操作，可以暴力做一些事情
我们按照顺序枚举操作：
- 假如是增加操作，就暴力给位置加值（初始 0）
- 假如是查询操作，则暴力枚举 [l, r] 中的每个数，假设第 i 个数被加了 s[i]，当前查出来的最大值是 m
  则 i 位置初始值不能超过 m - s[i]
把所有操作枚举完之后，每个位置的数都有一个上限了，我们可以取其恰好为上限（这样最可能满足题意）
*/

struct Operation {
    LL op, l, r, val;
};

int n, m;
LL s[N], a[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i] = 1e9;
    }
    vector<Operation> ops(m + 1);
    for (int i = 1; i <= m; i++) {
        LL op, l, r, mx, d;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> d;
            for (int j = l; j <= r; j++) {
                s[j] += d;
            }
            ops[i] = {op, l, r, d};
        } else {
            cin >> mx;
            for (int j = l; j <= r; j++) {
                a[j] = min(a[j], mx - s[j]);
            }
            ops[i] = {op, l, r, mx};
        }
    }
    int upper = 1e9;
    for (int i = 1; i <= n; i++) {
        if (a[i] > upper || a[i] < -upper) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        s[i] = a[i];
    }
    for (int i = 1; i <= m; i++) {
        if (ops[i].op == 1) {
            for (int j = ops[i].l; j <= ops[i].r; j++) {
                s[j] += ops[i].val;
            }
        } else {
            LL mx = -INF;
            for (int j = ops[i].l; j <= ops[i].r; j++) {
                mx = max(mx, s[j]);
            }
            if (mx != ops[i].val) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}
