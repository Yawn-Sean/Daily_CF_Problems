/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-30 18:56 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    const int MOD = 1e9 + 7;
    cin >> n >> m;
    vector s1(n + 1, 0), s2(n + 1, 0);
    auto fastpow = [&] (int a, int b) -> int {
        int res = 1;
        while (b) {
            if (b & 1) res = 1ll * a * res % MOD;
            a = 1ll * a * a % MOD;
            b >>= 1;
        }
        return res;
    };
    for (int i = 1; i <= n; i ++) {
        cin >> s1[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> s2[i];
    }
    int im = fastpow(m, MOD - 2);
    int now = 1;
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (s1[i] && s2[i]) {
            if (s1[i] > s2[i]) {
                ans += now;
                ans %= MOD;
                break;
            }
            if (s1[i] < s2[i]) {
                break;
            }
        } else if (s1[i] == 0 && s2[i] != 0) {
            ans += 1ll * (m - s2[i]) * im % MOD * now % MOD; 
            ans %= MOD;
            now = 1ll * now * im % MOD;
        } else if (s2[i] == 0 && s1[i] != 0) {
            ans += 1ll * (s1[i] - 1) * im % MOD * now % MOD;
            ans %= MOD;
            now = 1ll * now * im % MOD;
        } else {
            ans += 1ll * (m - 1) * fastpow(2, MOD - 2) % MOD * im % MOD * now % MOD;
            ans %= MOD;
            now = 1ll * now * im % MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
