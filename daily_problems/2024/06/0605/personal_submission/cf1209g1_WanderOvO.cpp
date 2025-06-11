/*
每种数字最左和最右的出现位置
假如值为 val 的段里面出现了别的数，则要么把 val 变成别的数，要么把别的数都变成 val
如果把别的数都变成 val，则为 val 的段就更大了，可能会包含更多
假如某个段完全被另一个段包含了，则这个小段可以把值变得和大段一样
所有相交的段必须最后变成一样的，所以其实就是保留本身最长的段，其他的变成这个段
*/

int T;
int a[N], n, q;
int l[N], r[N], cnt[N];

struct Segment {
    int l, r, cnt;

    bool operator<(const Segment &o) const {
        if (l == o.l) {
            return r < o.r;
        }
        return l < o.l;
    }
};

void solve1() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if (l[a[i]] == 0) {
            l[a[i]] = i;
            r[a[i]] = i;
        } else {
            r[a[i]] = i;
        }
    }
    vector<Segment> segs;
    for (int i = 0; i < N; i++) {
        if (l[i] != 0) {
            Segment seg;
            seg.l = l[i];
            seg.r = r[i];
            seg.cnt = cnt[i];
            segs.pb(seg);
        }
    }
    sort(segs.begin(), segs.end());
    int left = segs[0].l, right = segs[0].r, maxlen = segs[0].cnt;
    int res = 0;
    for (int i = 1; i < segs.size(); i++) {
        if (segs[i].l <= right) {
            right = max(segs[i].r, right);
            maxlen = max(maxlen, segs[i].cnt);
        } else {
            res += (right - left + 1 - maxlen);
            left = segs[i].l;
            right = segs[i].r;
            maxlen = segs[i].cnt;
        }
    }
    res += (right - left + 1 - maxlen);
    cout << res << "\n";
}      