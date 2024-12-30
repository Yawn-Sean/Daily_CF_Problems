/*
所有线段按照左端点排序
枚举坐标点 i，考虑所有没删除的左端点 <= i 的线段
假如覆盖超过了 k 次，则优先把右端点大的删了
*/

int T;
SegmentTree tr;
PIII segs[N];
int n, k;

void solve1() {
    cin >> n >> k;
    tr.init(N - 1);
    for (int i = 1; i <= n; i++) {
        cin >> segs[i].x.x >> segs[i].x.y;
        segs[i].y = i;
        tr.add(1, N - 1, segs[i].x.x, segs[i].x.y, 1, 1);
    }
    sort(segs + 1, segs + n + 1);
    priority_queue<PIII> q;
    int cur_seg = 1;
    vector<int> deleted;
    for (int i = 1; i < N; i++) {
        while (cur_seg <= n && segs[cur_seg].x.x <= i) {
            q.push(mp(mp(segs[cur_seg].x.y, segs[cur_seg].x.x), segs[cur_seg].y));
            cur_seg++;
        }
        while (tr.query(1, N - 1, i, i, 1) > k) {
            PIII u = q.top();
            q.pop();
            int l = u.x.y, r = u.x.x, id = u.y;
            tr.add(1, N - 1, l, r, 1, -1);
            deleted.pb(id);
        }
    }
    cout << deleted.size() << "\n";
    for (auto id : deleted) {
        cout << id << " ";
    }
    cout << "\n";
}     