/*
按照左端点排序所有询问，左端点相同按照右端点
左端点一样的情况下，如何求出不同右端点的答案
我们不妨预处理每个位置的上一个和下一个和自己相同的位置，并记录和上一个相同位置的距离
按照以上顺序回答询问前
假如目前回答 [l, r] 内的答案，则先把 < l 的元素的下一个位置的距离设为无穷大
再查询 [l, r] 内的距离最小值
*/

int T;
int next_pos[N], d[N];
int n, m, a[N], res[N];
PIII queries[N];
SegmentTree tr;

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> queries[i].x.x >> queries[i].x.y;
        queries[i].y = i;
    }
    sort(queries + 1, queries + m + 1);
    map<int, int> pos;
    for (int i = 1; i <= n; i++) {
        if (pos.count(a[i])) {
            d[i] = i - pos[a[i]];
        } else {
            d[i] = INF;
        }
        pos[a[i]] = i;
    }
    pos.clear();
    for (int i = 1; i <= n; i++) {
        next_pos[i] = n + 1;
    }
    for (int i = n; i > 0; i--) {
        if (pos.count(a[i])) {
            next_pos[i] = pos[a[i]];
        }
        pos[a[i]] = i;
    }
    tr.init(n, d);
    int pt = 1;
    for (int i = 1; i <= m; i++) {
        int l = queries[i].x.x, r = queries[i].x.y, id = queries[i].y;
        while (pt < l) {
            if (next_pos[pt] <= n) {
                tr.modify(1, n, next_pos[pt], INF, 1);
            }
            pt++;
        }
        res[id] = tr.query(1, n, l, r, 1);
    }
    for (int i = 1; i <= m; i++) {
        if (res[i] == INF) {
            res[i] = -1;
        }
        cout << res[i] << "\n";
    }
}    