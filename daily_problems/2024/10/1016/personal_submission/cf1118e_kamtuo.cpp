/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-16 14:25 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    if (n > 1ll * (k - 1) * k) cout << "NO" << "\n";
    else {
        vector b(k, 0), g(k, 0);
        cout << "YES" << "\n";
        for (int i = 0; i < k; i ++) b[i] = i + 1, g[i] = i + 1;
        int l = 0, r = 1 % k;
        for (int i = 1; i <= n; i ++) {
            cout << b[l % k] << ' ' << g[r % k] << "\n";
            l ++, r ++;
            if (l == k) {
                r = i / k + 1;
                r %= k;
                l %= k;
            } 
        }
    }
    return 0;
}

#endif

/*

*/
