/*
只能买两座喷泉
买两个钻石/两个黄金/一黄金一钻石
分别组织两类喷泉，然后按照花费排序
对于两个钻石/两个黄金，固定价格小的那个，选价格大的那个
对于一黄金一钻石，固定黄金，选钻石
*/

int T;
LL n, c, d, cnt1, cnt2;
PLL f1[N], f2[N];
ST st_f1, st_f2;

void solve1() {
    cin >> n >> c >> d;
    for (int i = 1; i <= n; i++) {
        LL b, p;
        string type;
        cin >> b >> p >> type;
        if (type == "C") {
            f1[++cnt1] = {p, b};
        } else {
            f2[++cnt2] = {p, b};
        }
    }
    sort(f1 + 1, f1 + cnt1 + 1);
    sort(f2 + 1, f2 + cnt2 + 1);

    st_f1.init_st(cnt1, f1);
    st_f2.init_st(cnt2, f2);
    // cout << cnt1 << " " << cnt2 << "\n";

    LL res = 0;
    for (int i = 1; i < cnt1; i++) {
        LL maxcost = c - f1[i].x;
        if (maxcost >= 0) {
            PLL u = {maxcost, INF};
            int pos = upper_bound(f1 + i + 1, f1 + cnt1 + 1, u) - f1;
            pos--;
            if (pos >= i + 1 && pos <= cnt1) {
                res = max(res, f1[i].y + st_f1.query(i + 1, pos));
            }
        }
    }
    for (int i = 1; i < cnt2; i++) {
        LL maxcost = d - f2[i].x;
        if (maxcost >= 0) {
            PLL u = {maxcost, INF};
            int pos = upper_bound(f2 + i + 1, f2 + cnt2 + 1, u) - f2;
            pos--;
            if (pos >= i + 1 && pos <= cnt2) {
                res = max(res, f2[i].y + st_f2.query(i + 1, pos));
            }
        }
    }
    for (int i = 1; i <= cnt1; i++) {
        if (f1[i].x > c) continue;
        LL maxcost = d;
        if (maxcost >= 0) {
            PLL u = {maxcost, INF};
            int pos = upper_bound(f2 + 1, f2 + cnt2 + 1, u) - f2;
            pos--;
            if (pos >= 1 && pos <= cnt2) {
                res = max(res, f1[i].y + st_f2.query(1, pos));
            }
        }
    }
    cout << res << "\n";
}      