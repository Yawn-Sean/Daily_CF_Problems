/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-23 18:14 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    const int MOD = 998244353;
    vector s(n + 1, 0), t(m + 1, 0), tr(211111, 0);
    auto lowbit = [&] (int x) -> int {
        return x & -x;
    };
    auto add = [&] (int x, int v) {
        for (int i = x; i <= 200000; i += lowbit(i)) tr[i] += v;
    };
    auto query = [&] (int x) -> int {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    };
    auto fastpow = [&] (int a, int b) -> int {
        int res = 1;
        while (b) {
            if (b & 1) res = 1ll * res * a % MOD;
            a = 1ll * a * a % MOD;
            b >>= 1;
        }
        return res;
    };
    for (int i = 1; i <= n; i ++) cin >> s[i], add(s[i], 1);
    for (int i = 1; i <= m; i ++) cin >> t[i];
    vector fac(n + 1, 0), inv(n + 1, 0);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i ++) {
        fac[i] = 1ll * i * fac[i - 1] % MOD;
        inv[i] = fastpow(fac[i], MOD - 2);
    }
    int now = fac[n];
    for (int i = 1; i <= 200000; i ++) {
        now = 1ll * now * inv[(query(i) - query(i - 1))] % MOD;
    }
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        if (query(200000) == 0) {
            ans ++;
            ans %= MOD;
        }
        if (query(t[i]) == 0) {
            break;
        } 
        now = 1ll * now * fastpow(n - i + 1, MOD - 2) % MOD;
        ans += 1ll * now * query(t[i] - 1) % MOD;
        ans %= MOD;
        now = 1ll * now * (query(t[i]) - query(t[i] - 1)) % MOD;
        add(t[i], -1);
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
