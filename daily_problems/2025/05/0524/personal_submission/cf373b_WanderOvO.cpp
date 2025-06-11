/*
极限状态下数字可能有多大？
最多是 w = 1e16，k = 1，m = 1e16
每个数有 17 位，有 17 位的数有 9e16 个，所以不会爆 long long
把位数一样的数放到一起统计
*/

LL w, m, k;

void meibao() {
    cin >> w >> m >> k;
    w /= k;
    LL res = 0;

    auto get_cnt = [&] (LL val) -> int {
        LL cnt = 0;
        while (val > 0) {
            cnt++;
            val /= 10;
        }
        return cnt;
    };

    LL st = m;
    while (w > 0) {
        LL cnt = get_cnt(st);
        LL mx = pow(10, cnt);
        mx--;
        if ((mx - st + 1) <= w / cnt) {
            w -= (mx - st + 1) * cnt;
            res += mx - st + 1;
            st = mx + 1;
        } else {
            res += w / cnt;
            w = 0;
        }
    }
    cout << res << "\n";
}    
