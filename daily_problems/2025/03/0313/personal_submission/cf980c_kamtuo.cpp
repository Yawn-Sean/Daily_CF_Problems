/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-13 14:28                         */
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
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int n, k;
    const int N = 300;
    cin >> n >> k;
    vector p(N, 0), sz(N, 1), minp(N, 0);
    for (int i = 1; i < N; i ++) p[i] = i, minp[i] = i;
    std::function<int (int)> find = [&] (int x) -> int {
        if (p[x] - x) p[x] = find(p[x]);
        return p[x];
    };
    vector col(257, 0), a(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] ++;
        int x = a[i];
        for (int j = 0; j <= k; j ++) {
            if (x - j <= 0) break;
            int fx = find(x), fy = find(x - j);
            if (fx == fy) continue;
            if (sz[fx] + sz[fy] <= k) {
                sz[fy] += sz[fx];
                p[fx] = fy;
            } else break;
        }
    }
    for (int i = 1; i <= n; i ++) {
        // cout << a[i] << "\n";
        cout << find(a[i]) - 1 << ' ';
    }
    return 0;
}

#endif

/*

*/
