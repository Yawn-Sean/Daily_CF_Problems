/*
枚举在第 i 天购买商品
用前 i 天中最便宜的兑换汇率，把美元和英镑转化为卢布，选其中最便宜的 m 个，看钱够不够
有单调性，可以二分
*/

int T;
LL n, m, k, s, a[N], b[N], t[N], c[N], mina_time[N], minb_time[N];
PLL products[N];

bool check(int ans) {
    for (int i = 1; i <= m; i++) {
        products[i].x = (t[i] == 1 ? (a[ans] * c[i]) : (b[ans] * c[i]));
        products[i].y = i;
    }
    sort(products + 1, products + m + 1);
    LL cost = 0;
    for (int i = 1; i <= k; i++) {
        cost += products[i].x;
    }
    return cost <= s;
}

void solve1() {
    cin >> n >> m >> k >> s;
    a[0] = INF;
    b[0] = INF;
    mina_time[0] = 0;
    minb_time[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > a[i - 1]) {
            a[i] = a[i - 1];
            mina_time[i] = mina_time[i - 1];
        } else {
            mina_time[i] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] > b[i - 1]) {
            b[i] = b[i - 1];
            minb_time[i] = minb_time[i - 1];
        } else {
            minb_time[i] = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i] >> c[i];
    }

    int l = 1, r = n, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cout << l << "\n";
        for (int i = 1; i <= k; i++) {
            int id = products[i].y;
            int day = (t[id] == 1 ? mina_time[l] : minb_time[l]);
            cout << id << " " << day << "\n";
        }
    } else if (check(r)) {  
        cout << r << "\n";
        for (int i = 1; i <= k; i++) {
            int id = products[i].y;
            int day = (t[id] == 1 ? mina_time[r] : minb_time[r]);
            cout << id << " " << day << "\n";
        }
    } else {
        cout << "-1\n";
    }
}       