/*
枚举最高位，计算最高位乘以阶数之后的余数，从而知道了剩下的 k - 1 位数的余数应该是多少（注意 0）
只需要求至多 k - 1 位的数中 [0, 9...9]，有多少数的余数是 m 即可，即 [0, 9...9 - m] 中，有多少数能被 a[i] 整除
*/

LL n, k, a[N], b[N], cnt;

void meibao() {
    cin >> n >> k;
    cnt = n / k;
    for (int i = 1; i <= cnt; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= cnt; i++) {
        cin >> b[i];
    }

    LL res = 1;
    int mod = MOD1;
    for (int i = 1; i <= cnt; i++) {
        LL ans = 0;
        for (LL t = 0; t <= 9; t++) {
            if (t == b[i]) {
                continue;
            }
            LL val = t;
            for (int j = 1; j < k; j++) {
                val *= 10;
            }
            val %= a[i];
            LL m = (a[i] - val) % a[i];
            LL mx = 1;
            for (int j = 1; j < k; j++) {
                mx *= 10;
            }
            mx--;
            mx -= m;
            if (mx >= 0) {
                ans += (mx / a[i] + 1);
            }
        }
        res *= ans;
        res %= mod;
    }
    cout << res << "\n";
}
