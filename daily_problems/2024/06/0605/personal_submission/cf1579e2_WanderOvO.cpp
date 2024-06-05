/*
对于 a[i]
- 假如插入到右边，则要和所有 a[1]-a[i - 1] 中比自己大的计算逆序对
- 假如插入到左边，则要和所有 a[1]-a[i - 1] 中比自己小的计算逆序对
所以相当于每个数有两种选择，每种选择的贡献是确定的，和之前怎么选择的也没有关系，可以 DP
*/

int T;
LL a[N], b[N], n;
BIT tr;

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int m = unique(b + 1, b + n + 1) - b;
    tr.init(n);
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(b + 1, b + m + 1, a[i]) - b;
        LL lower_cnt = tr.query(pos - 1);
        LL upper_cnt = i - 1 - tr.query(pos);
        res += min(lower_cnt, upper_cnt);
        tr.add(pos, 1);
    }
    tr.init(n);
    cout << res << "\n";
}           