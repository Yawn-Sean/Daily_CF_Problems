/*
每个操作都有一个初始下标 i
在执行查询操作 i 时，要把比 i 小且时间也更小的其他修改操作都执行了，然后才能查
可以单独考虑某个 x，只考虑这个 x 的增删改查，就可以树状数组了
*/

struct Query {
    int type, time, id;
};

int n;
BIT tr;
int a[N], t[N], x[N], b[N];
int idx = 0;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> t[i] >> x[i];
        b[++idx] = t[i];
        b[++idx] = x[i];
    }
    sort(b + 1, b + idx + 1);
    for (int i = 1; i <= n; i++) {
        t[i] = lower_bound(b + 1, b + idx + 1, t[i]) - b;
        x[i] = lower_bound(b + 1, b + idx + 1, x[i]) - b;
    }
    vector<vector<Query>> qs(idx + 1);
    for (int i = 1; i <= n; i++) {
        qs[x[i]].pb({a[i], t[i], i});
    }
    vector<PII> res;
    tr.init(idx);
    for (int i = 1; i <= idx; i++) {
        for (int j = 0; j < qs[i].size(); j++) {
            auto &cur = qs[i][j];
            if (cur.type == 1) {
                tr.add(cur.time, 1);
            } else if (cur.type == 2) {
                tr.add(cur.time, -1);
            } else {
                int cnt = tr.query(cur.time);
                res.pb({cur.id, cnt});
            }
        }
        for (int j = 0; j < qs[i].size(); j++) {
            auto &cur = qs[i][j];
            if (cur.type == 1) {
                tr.add(cur.time, -1);
            } else if (cur.type == 2) {
                tr.add(cur.time, 1);
            } 
        }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].y << "\n";
    }
}     
