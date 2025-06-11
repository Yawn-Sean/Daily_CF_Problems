/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-23 19:37 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    const int MOD = 1000000009;
    cin >> n >> m >> k;
    auto fastpower = [&] (int a, int b) -> int {
        int res = 1;
        while (b) {
            if (b & 1) res = 1ll * res * a % MOD;
            a = 1ll * a * a % MOD;
            b >>= 1;
        }
        return res;
    };
    int now = min(m, n - n / k) - 1ll * (k - 1) * (m - min(m, n - n / k));
    cout << (((1ll * k * (fastpower(2, m - min(m, n - n / k) + 1) - 2) + now + MOD))) % MOD << "\n";
    return 0;
}

#endif

/*

*/
