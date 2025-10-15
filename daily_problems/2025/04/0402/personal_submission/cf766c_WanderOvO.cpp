int n, a[M];
string s;

void calc1() {
    int dp[N] = {0};
    int mod = 1e9 + 7;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int mincnt = INF;
        for (int j = i; j > 0; j--) {
            mincnt = min(mincnt, a[s[j] - 'a']);
            if (i - j + 1 <= mincnt) {
                dp[i] += dp[j - 1];
                dp[i] %= mod;
            } else {
                break;
            }
        }
    }
    cout << dp[n] << "\n";
}

void calc2() {
    int b[N] = {0};
    for (int i = 1; i <= n; i++) {
        b[i] = a[s[i] - 'a'];
    }

    int st[N][12];
    for (int i = 1; i <= n; i++) {
        st[i][0] = b[i];
    }

    for (int j = 1; j < 12; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    int lg[N] = {0};
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }

    auto query = [&] (int l, int r) -> int {
        int k = lg[r - l + 1];
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    };

    auto check = [&] (int ans) -> bool {
        for (int i = 1; i + ans - 1 <= n; i++) {
            if (query(i, i + ans - 1) >= ans) {
                return true;
            }    
        }
        return false;
    };

    int l = 1, r = n, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (check(r)) {
        cout << r << "\n";
    } else {
        cout << l << "\n";
    }
}

void calc3() {
    int dp[N];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int mincnt = INF;
        for (int j = i; j > 0; j--) {
            mincnt = min(mincnt, a[s[j] - 'a']);
            if (mincnt >= i - j + 1) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            } else {
                break;
            }
        }
    }
    cout << dp[n] << "\n";
}

void meibao() {
    cin >> n >> s;
    s = " " + s;
    for (int i = 0; i < 26; i++) {
        cin >> a[i];
    }
    calc1();
    calc2();
    calc3();
}
