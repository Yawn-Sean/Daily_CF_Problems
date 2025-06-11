/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-16 18:03 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int even = 0, odd = 0;
    bool ok = 0;
    for (int i = 1; i <= q; i ++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            odd += x;
            odd = odd % n + n;
            odd %= n;
            even += x;
            even = even % n + n;
            even %= n;
            ok ^= ((x % 2) + 2) % 2;
        } else {
            if (ok) {
                even += 1;
                odd -= 1;
            } else {
                even -= 1;
                odd += 1;
            }
            ok ^= 1;
        }
    }
    vector ans(n, 0);
    for (int i = 0; i < n; i ++) {
        if (i % 2) ans[((i + even) % n + n) % n] = i + 1;
        else ans[(((i + odd) % n) + n) % n] = i + 1;
    }
    for (int i = 0; i < n; i ++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;

}

#endif

/*

*/
