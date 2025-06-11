/*
击败所有怪兽的最小天数，需要按照顺序击败怪兽
首先排除怪兽力量值 > 英雄力量最大值的情况
相同天数，打败得多比打败得少一定更优，因为后面最差也可以用和少的一样的策略打
当前需要打第 i 个怪兽，枚举英雄 j，计算能打到哪个，取最大的 mx，i = mx + 1
英雄按照力量值排个序
当前正在打第 i 个怪兽，二分至少能打 cnt 个怪兽
求 [i, i + cnt - 1] 的怪兽力量最大值，然后在英雄里面二分，找到哪个后缀的英雄可以
维护 s[i] 的后缀最大值即可 
*/ 

struct Hero {
    int p, s;

    bool operator<(const Hero &o) const {
        return p < o.p;
    }
};

Hero heros[N];
int a[N], n, m, max_s[N];
ST st_table;

bool check(int st, int cnt) {
    int max_p = st_table.query(st, st + cnt - 1);
    Hero h;
    h.p = max_p;
    h.s = -1;
    int pos = lower_bound(heros + 1, heros + m + 1, h) - heros;
    if (pos == m + 1) {
        return false;
    }
    return max_s[pos] >= cnt;
}

void meibao() {
    cin >> n;
    int max_a = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> heros[i].p >> heros[i].s;
    }
    
    sort(heros + 1, heros + m + 1);
    st_table.init_st(a, n);

    max_s[m + 1] = 0;
    for (int i = m; i > 0; i--) {
        max_s[i] = max(max_s[i + 1], heros[i].s);
    }
    if (heros[m].p < max_a) {
        cout << "-1\n";
        return;
    }

    int cur = 1, res = 0;
    while (cur <= n) {
        int l = 1, r = n - cur + 1, mid;
        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            if (check(cur, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        res++;
        if (check(cur, r)) {
            cur += r;
        } else if (check(cur, l)) {
            cur += l;
        } else {
            cout << "-1\n";
            return;
        }
    }
    cout << res << "\n";
}
