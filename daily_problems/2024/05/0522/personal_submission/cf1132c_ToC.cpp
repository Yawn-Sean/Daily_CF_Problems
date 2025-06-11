// https://codeforces.com/contest/1132/submission/262241187
struct Seg {
    int l, r;
};
Seg seg[MAXN];
void sol()
{   
    cin >> n >> q;
    int l, r;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        seg[i].l = l, seg[i].r = r;
        cnt[l] += 1, cnt[r + 1] -= 1;
    }
    for (int i = 2; i <= n; i++)
        cnt[i] += cnt[i - 1]; 

    Fenwick f1(MAXN), f2(MAXN);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) {
            f1.add(i, 1);
        } else if (cnt[i] == 2) {
            f2.add(i, 1);
        }
        if (cnt[i] != 0) tot++;
    }
    int res = -1;
    for (int i = 1; i < q; i++) {
        for (int j = i + 1; j <= q; j++) {
            int l1 = seg[i].l, l2 = seg[j].l;
            int r1 = seg[i].r, r2 = seg[j].r;
            int maxl = max(l1, l2), minr = min(r1, r2);
            int minl = min(l1, l2), maxr = max(r1, r2);

            int tmp = 0;
            if (maxl <= minr) {
                // cout << "joint\n";
                // tmp += f2.range(minr, maxl);
                tmp = f2.range(maxl, minr);
                if (minl <= maxl - 1) tmp += f1.range(minl, maxl - 1);
                if (maxr >= minr + 1) tmp += f1.range(minr + 1, maxr);
            } else {
                tmp = (f1.range(l1, r1) + f1.range(l2, r2));
            }
            res = max(res, tot - tmp);
        }
    }
    cout << res << '\n';
}
