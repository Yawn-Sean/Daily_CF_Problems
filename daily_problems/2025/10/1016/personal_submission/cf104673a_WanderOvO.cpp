/*
标签是 1e9，而 C(n, 2) 在 n = 1e5 时显然已经超过了 1e9
我们预处理 n = 2e3 以内的组合数，以及每种数第一次出现的行
对于查不到的，要么是 C(n, 1), C(n, 2), C(n, 3)，直接特判计算一下即可
*/ 

LL c[M][M], n, q;
map<LL, int> pos;

void meibao() {
    cin >> q;
    c[0][0] = 1;
    pos[1] = 0;
    LL mx = 1e9;
    for (int i = 1; i < M; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            if (c[i][j] >= 1 && c[i][j] <= mx && !pos.count(c[i][j])) {
                pos[c[i][j]] = i;
            }
        }
    }

    auto calc1 = [&] (LL val) -> LL {
        LL l = 1, r = 1e5, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (mid * (mid - 1) / 2 <= val) {
                l = mid;
            } else {
                r = mid;
            }
        }

        LL res = 0;
        if (r * (r - 1) / 2 <= val) {
            res = r;
        } else {
            res = l;
        }
        if (res * (res - 1) / 2 == val) {
            return res;
        }
        return INFLL;
    };

    auto calc2 = [&] (LL val) -> LL {
        LL l = 1, r = 5000, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (mid * (mid - 1) * (mid - 2) / 6 <= val) {
                l = mid;
            } else {
                r = mid;
            }
        }

        LL res = 0;
        if (r * (r - 1) * (r - 2) / 6 <= val) {
            res = r;
        } else {
            res = l;
        }
        if (res * (res - 1) * (res - 2) / 6 == val) {
            return res;
        }
        return INFLL;
    };

    while (q--) {
        LL n;
        cin >> n;
        if (pos.count(n)) {
            cout << pos[n] + 1 << "\n";
        } else {
            LL r1 = calc1(n), r2 = calc2(n), r3 = n;
            cout << min({r1, r2, r3}) + 1 << "\n";
        }
    }
}   
