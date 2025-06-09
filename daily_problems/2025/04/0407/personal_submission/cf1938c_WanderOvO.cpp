LL n, p[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    LL res = (1LL << p[1]) - 1;
    for (int i = 1; i < n; i++) {
        int cnt = p[i] - p[i + 1] + 1;
        if (cnt >= 0) {
            LL val1 = (1LL << (p[i] + 1)) - 1;
            LL val2 = val1 - (1LL << cnt);
            res = max(res, val2 - i + 1);
        }
    }

    auto calc = [&] (LL x) -> int {
        int res = 0;
        while (x > 0) {
            if (x & 1) {
                res++;
            }
            x >>= 1;
        }
        return res;
    };

    // cout << res << "\n";

    for (int i = 1; i <= n; i++) {
        if (calc(i + res - 1) != p[i]) {
            cout << "-1\n";
            return;
        }
    }
    cout << res << "\n";
}   
