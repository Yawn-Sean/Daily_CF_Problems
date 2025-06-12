/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-06-12 11:03                         */
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
        vector<string> s(n);
        for (int i = 0; i < n; i ++) cin >> s[i];
        vector u(10, n), d(10, -1), l(10, n), r(10, -1);
        vector ans(10, 0);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int now = s[i][j] - '0';
                u[now] = min(u[now], i);
                d[now] = max(d[now], i);
                l[now] = min(l[now], j);
                r[now] = max(r[now], j);
            }
        }
        for (int i = 0; i < n; i ++) {
            vector ll(10, n);
            for (int j = 0; j < n; j ++) {
                int now = s[i][j] - '0';
                ll[now] = min(ll[now], j);
                ans[now] = max(ans[now], (j - ll[now]) * max(i - u[now], d[now] - i));
                ans[now] = max(ans[now], (j - ll[now]) * max(i, n - 1 - i));
                ans[now] = max(ans[now], j * max(i - u[now], d[now] - i));
                for (int k = 0; k < 10; k ++) {
                    // if (ll[k] == n) continue;
                    ans[k] = max(ans[k], (j - min(ll[k], j)) * max(i - min(u[k], i), max(d[k], i) - i));
                }

            }
        }
        for (int j = 0; j < n; j ++) {
            vector ll(10, n);
            for (int i = 0; i < n; i ++) {
                int now = s[i][j] - '0';
                ll[now] = min(ll[now], i);
                ans[now] = max(ans[now], (i - ll[now]) * max(j - l[now], r[now] - j));
                ans[now] = max(ans[now], (i - ll[now]) * max(j, n - 1 - j));
                ans[now] = max(ans[now], i * max(j - l[now], r[now] - j));
                for (int k = 0; k < 10; k ++) {
                    // if (ll[k] == n) continue;
                    ans[k] = max(ans[k], (i - min(ll[k], i)) * max(j - min(l[k], j), max(r[k], j) - j));
                }

            }
        }
        for (int i = 0; i < 10; i ++) {
            cout << ans[i] << ' ';
        }
        cout << "\n";
    }
    return 0;
}

#endif

/*

*/
