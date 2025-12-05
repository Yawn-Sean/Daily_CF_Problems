/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-12-04 21:13                         */
/* Software : Visual Studio Code                            */
/*                                                          */
/*  ██╗  ██╗ █████╗ ███╗   ███╗████████╗██╗   ██╗ ██████╗   */
/*  ██║ ██╔╝██╔══██╗████╗ ████║╚══██╔══╝██║   ██║██╔═══██╗  */
/*  █████╔╝ ███████║██╔████╔██║   ██║   ██║   ██║██║   ██║  */
/*  ██╔═██╗ ██╔══██║██║╚██╔╝██║   ██║   ██║   ██║██║   ██║  */
/*  ██║  ██╗██║  ██║██║ ╚═╝ ██║   ██║   ╚██████╔╝╚██████╔╝  */
/*  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝   ╚═╝    ╚═════╝  ╚═════╝   */
/*----------------------------------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector a(n + 1, 0ll);
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        vector stk(1, n + 1);
        vector sa(1, 0ll);
        LL ans = 0;
        for (int i = n; i >= 0; i --) {
            while (stk.back() != n + 1 && a[stk.back()] < a[i]) {
                stk.pop_back();
                sa.pop_back();
            }
            // sa.push_back(i);
            sa.push_back(sa.back() + (stk.back() - i * 1ll) * a[i]);
            stk.push_back(i);
            ans += sa.back() - 1ll * (n - i + 1) * a[i];
        }
        cout << ans << "\n";
    }
    return 0;
}

#endif

/*

*/
