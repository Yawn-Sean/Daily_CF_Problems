/*
slice operation 之后，保留 > mid 或者 <= mid 的所有数，抛弃另一部分
顺序有影响吗？看起来每次操作只和值的大小有关，和顺序无关
暴力模拟这个过程的复杂度是多少？
- 一种情况是类似线段树一样均匀分割，需要处理约 4n 个区间，每个区间需要做一次二分，总复杂度 O(nlogn)
- 另一种情况是每次分得很不均匀，需要处理 O(n) 个区间，总复杂度也是 O(nlogn)
*/

int T;
LL n, q, a[N], s[N];
set<LL> vals;

void build(int l, int r) {
    if (l > r) {
        return;
    }
    LL sum = s[r] - s[l - 1];
    vals.insert(sum);
    LL avg = (a[l] + a[r]) / 2;
    int pos = upper_bound(a + l, a + r + 1, avg) - a;
    if (pos == r + 1) {
        return;
    } else {
        build(l, pos - 1);
        build(pos, r);
    }
}

void solve1() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    vals.clear();
    build(1, n);
    while (q--) {
        LL sum;
        cin >> sum;
        if (vals.count(sum)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}        