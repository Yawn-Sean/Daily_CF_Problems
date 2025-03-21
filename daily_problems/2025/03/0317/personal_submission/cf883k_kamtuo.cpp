/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-17 14:20                         */
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
    int n;
    cin >> n;
    vector s(n, 0), g(n, 0), v(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> s[i] >> g[i];
        v[i] = s[i] + g[i];
    }
    for (int i = 1; i < n; i ++) {
        v[i] = min(v[i - 1] + 1, v[i]);
    }
    for (int i = n - 2; i >= 0; i --) {
        v[i] = min(v[i + 1] + 1, v[i]);
    }
    LL ans = 0;
    for (int i = 0; i < n; i ++) {
        if (v[i] < s[i]) {
            cout << -1;
            return 0;
        }
        ans += v[i] - s[i];
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i ++) {
        cout << v[i] << ' ';
    }
    return 0;
}

#endif

/*

*/
