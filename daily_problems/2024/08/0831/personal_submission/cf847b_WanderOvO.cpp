/*
最大值一定出现在第一个子序列中
第二个子序列的最大值一定小于第一个子序列的最大值
记录每个元素所在的递增子序列的序列 id
直接模拟，把所有序列当前最后一个元素及其所在序列 id 维护一下
每次找 id 最小且值 < 当前元素的元素所在序列，加进去，更新信息
假如不存在这样的 id，就新开一个子序列
似乎可以以 id 为下标，最后一个元素的值作为值建立线段树，维护单点查询，单点修改和前缀 min，结合二分模拟这个过程
*/

int T;
int n, a[N], b[N], id[N];
SegmentTree tr;

bool check(int ans, int val) {
    int res = tr.range_min(1, n, 1, ans, 1);
    return res < val;
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = INF;
    }
    tr.init(n, b);
    int idx = 0;
    id[1] = ++idx;
    tr.modify(1, n, 1, a[1], 1);
    for (int i = 2; i <= n; i++) {
        int l = 1, r = idx, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(mid, a[i])) {
                r = mid;
            } else {
                l = mid;
            }
        }
        int pos = -1;
        if (check(l, a[i])) {
            pos = l;
        } else if (check(r, a[i])) {
            pos = r;
        } 
        if (pos == -1) {
            idx++;
            id[i] = idx;
            tr.modify(1, n, idx, a[i], 1);
        } else {
            id[i] = pos;
            tr.modify(1, n, pos, a[i], 1);
        }
    }
    vector<vector<int>> res(idx + 1);
    for (int i = 1; i <= n; i++) {
        res[id[i]].pb(a[i]);
    }
    for (int i = 1; i <= idx; i++) {
        for (auto val : res[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }
}     
