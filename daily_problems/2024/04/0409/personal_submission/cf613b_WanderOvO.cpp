/*
尽量多的满级，且尽量大的最小值，主要看哪个贡献比较多
排序，枚举满级个数，然后把最大的那几个弄成满级，剩下的贪心地往最小值上加
二分最小值是多少，然后验证能否保证这一点
*/

int T;
LL n, A, cf, cm, m, a[N], s[N];
PLL b[N];

bool check(LL ans, LL left_m, LL cnt) {
    int pos = lower_bound(a + 1, a + n - cnt + 1, ans) - a;
    if (pos > n - cnt) {
        // 没有比 ans 大的
        pos--;
    } 
    if (a[pos] > ans) {
        pos--;
    }
    return pos * ans - s[pos] <= left_m;
}

bool cmp(const PLL &a, const PLL &b) {
    return a.y < b.y;
}

void solve1() {
    cin >> n >> A >> cf >> cm >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i].x = a[i];
        b[i].y = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    
    LL res = 0;
    // 枚举满级个数
    LL maxcnt = 0, minval = 0;
    for (int cnt = 0; cnt <= n; cnt++) {
        LL left_m = m - (cnt * A - s[n] + s[n - cnt]);
        if (left_m < 0) {
            break;
        }

        LL l = 0, r = A, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(mid, left_m, cnt)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (check(r, left_m, cnt)) {
            if (res < cf * cnt + cm * r) {
                res = cf * cnt + cm * r;
                maxcnt = cnt;
                minval = r;
            }
        } else {
            if (res < cf * cnt + cm * l) {
                res = cf * cnt + cm * l;
                maxcnt = cnt;
                minval = l;
            }
        }
    }
    cout << res << "\n";
    for (int i = n; i >= n - maxcnt + 1; i--) {
        b[i].x = A;
    }
    for (int i = n - maxcnt; i > 0; i--) {
        if (b[i].x < minval) {
            b[i].x = minval;
        }
    }
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << b[i].x << " ";
    }
}       