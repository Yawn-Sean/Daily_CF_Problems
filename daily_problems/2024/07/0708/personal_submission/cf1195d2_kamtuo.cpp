const int N = 123456, MOD = 998244353;

int a[N], cnt[N];
int a_len[N];
int n;
LL ans;

LL fastpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b % 2) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        int now = a[i];
        int len = 0;
        while (now) {
            len ++;
            now /=  10;
        }
        a_len[i] = len;
        cnt[len] ++;
    }

    for (int i = 1; i <= n; i ++) {
        int now = a[i];
        LL big = 1;
        LL bx = 10;
        LL n_cnt = 0;
        LL n_len = 0;
        for (int j = 1; j <= 10; j ++) {
            n_cnt += cnt[j];
        }
        while (now) {
            ans = ans + big * now % MOD * cnt[n_len] % MOD;
            ans %= MOD;
            ans = ans + bx * fastpow(10, MOD - 2) % MOD * now % MOD * cnt[n_len] % MOD;
            ans %= MOD;
            n_cnt -= cnt[n_len];
            ans %= MOD;
            ans = ans + big * (now % 10) % MOD * n_cnt % MOD;
            ans %= MOD;
            ans = ans + bx * (now % 10) % MOD * n_cnt % MOD;
            ans %= MOD;
            big = big * 100 % MOD;
            bx = bx * 100 % MOD;
            now /= 10;
            n_len ++;
        }
    }
    cout << ans << "\n";
    return 0;
}
