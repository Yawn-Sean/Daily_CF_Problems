/*
只可能有 3 种数字
枚举 1 种数字的个数，由于和是一定的，所以另外两种数的个数也确定了
ax + by = c，但 x + 2 = y，只可能有一个解
然后比较相同个数即可
*/ 

LL n, mn, mx;
map<LL, LL> cnt;

void meibao() {
    mn = INF;
    mx = -INF;
    cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        LL val;
        cin >> val;
        sum += val;
        cnt[val]++;
        mn = min(mn, val);
        mx = max(mx, val);
    }
    set<LL> candidates;
    for (int i = mn; i <= mx; i++) {
        candidates.insert(i);
    }
    if (mn == mx) {
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            cout << mn << " ";
        }
        return;
    }

    if (mn + 1 == mx) {
        cout << n << "\n";
        for (auto it : cnt) {
            for (int i = 1; i <= it.y; i++) {
                cout << it.x << " ";
            }
        }
        return;
    }

    LL res = n, res_cnt1 = 0, res_cnt2 = 0, res_cnt3 = 0;
    for (LL cnt1 = 0; cnt1 <= n; cnt1++) {
        LL left = sum - cnt1 * mn;
        LL cnt3 = left - (n - cnt1) * (mn + 1);
        if (cnt3 >= 0 && cnt3 <= n - cnt1) {
            LL cnt2 = n - cnt1 - cnt3;
            LL ans = min(cnt[mn], cnt1) + min(cnt[mn + 1], cnt2) + min(cnt[mn + 2], cnt3);
            if (ans <= res) {
                res = ans;
                res_cnt1 = cnt1;
                res_cnt2 = cnt2;
                res_cnt3 = cnt3;
            }
        }
    }
    cout << res << "\n";
    for (int i = 1; i <= res_cnt1; i++) {
        cout << mn << " ";
    }
    for (int i = 1; i <= res_cnt2; i++) {
        cout << mn + 1 << " ";
    }
    for (int i = 1; i <= res_cnt3; i++) {
        cout << mn + 2 << " ";
    }
}
