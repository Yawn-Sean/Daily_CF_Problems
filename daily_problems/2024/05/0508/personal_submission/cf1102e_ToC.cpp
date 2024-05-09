// https://codeforces.com/contest/1102/submission/260014131
int a[MAXN];
struct SEG {
    int l;
    int r;
};
SEG seg[MAXN];
int cnt;
map<int, PII> v2i;
bool cmp(SEG &a, SEG &b) {
    return a.l < b.l;
}
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (v2i.count(a[i])) {
            v2i[a[i]].second = i;
        } else {
            v2i[a[i]] = {i, i};
        }
    }
    int left = -1, right = 0;
    cnt = 1;
    for (auto &p : v2i) {
        seg[cnt].l = p.second.first;
        seg[cnt++].r = p.second.second;
    }
    sort(seg + 1, seg + cnt, cmp);
    int m = 0, l = -1, r = 0;
    for (int i = 1; i < cnt; i++) {
        if (seg[i].l > r) {
            m++;
            l = seg[i].l, r = seg[i].r;
        } else {
            r = max(r, seg[i].r);
        }
    }
    LL res = 1;
    for (int i = 1; i < m; i++)
        (res *= 2) %= mod2;
    cout << res << '\n';
}
