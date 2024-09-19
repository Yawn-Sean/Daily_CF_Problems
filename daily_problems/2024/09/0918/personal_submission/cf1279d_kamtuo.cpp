/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-18 09:17 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    const int MOD = 998244353;
    auto fastpow = [&] (int a, int b) -> int {
        int res = 1;
        while (b) {
            if (b & 1) res = 1ll * res * a % MOD;
            a = 1ll * a * a % MOD;
            b >>= 1;
        }
        return res;
    };
    vector cnt(1111111, 0), p(1111111, 0);
    vector a(n, vector<int> ());
    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j ++) {
            int x;
            cin >> x;
            cnt[x] ++;
            a[i].push_back(x);
            p[x] += 1ll * fastpow(k, MOD - 2) * fastpow(n, MOD - 2) % MOD;
            p[x] %= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 1000000; i ++) {
        ans += 1ll * p[i] * (1ll * cnt[i] * fastpow(n, MOD - 2) % MOD) % MOD;
        ans %= MOD;  
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
