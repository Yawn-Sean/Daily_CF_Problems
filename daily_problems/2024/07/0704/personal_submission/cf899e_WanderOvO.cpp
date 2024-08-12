/*
预处理所有连续段，存起点，长度，值，段的 id(链表索引)
连续段扔到堆里面
每个段维护一个是否还合法，删除或者合并的就不合法了
每次按照 (长度，起点) 弹出要删除的最长最左合法连续段
删完了看左右两边能否合并
*/

struct Node {
    int st, len, val, id, pre, ne;

    bool operator<(const Node &o) const {
        if (len == o.len) {
            return st > o.st;
        }
        return len < o.len;
    }
};

int T;  
int n, a[N], idx;
Node segs[N];
bool deleted[N];
priority_queue<Node> q;

void del_and_combine(int id) {
    deleted[id] = true;
    auto &cur = segs[id];
    if (cur.pre > 0 && cur.ne > 0) {
        assert(!deleted[cur.pre] && !deleted[cur.ne]);
        auto &pre = segs[cur.pre], &ne = segs[cur.ne];
        if (pre.val != ne.val) {
            pre.ne = ne.id;
            ne.pre = pre.id;
        } else {
            pre.len += ne.len;
            pre.ne = ne.ne;
            ne.pre = -1;
            if (ne.ne > 0) {
                auto &nene = segs[ne.ne];
                nene.pre = pre.id;
            }
            deleted[ne.id] = true;
            q.push(pre);
        }
    } else if (cur.pre > 0) {
        assert(!deleted[cur.pre]);
        auto &pre = segs[cur.pre];
        pre.ne = -1;
    } else if (cur.ne > 0) {
        assert(!deleted[cur.ne]);
        auto &ne = segs[cur.ne];
        ne.pre = -1;
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ) {
        int st = i;
        i++;
        for ( ; i <= n && a[i] == a[st]; i++);
        idx++;
        segs[idx].id = idx;
        segs[idx].len = i - st;
        segs[idx].st = st;
        segs[idx].val = a[st];
    }
    for (int i = 1; i <= idx; i++) {
        segs[i].pre = i - 1;
        segs[i].ne = i + 1;
    }
    segs[1].pre = -1;
    segs[n].ne = -1;

    for (int i = 1; i <= idx; i++) {
        q.push(segs[i]);
    }
    int res = 0;
    while (!q.empty()) {
        auto u = q.top();
        q.pop();
        if (deleted[u.id]) continue;
        res++;
        del_and_combine(u.id);
    }
    cout << res << "\n";
}