/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-04 14:39                         */
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
    vector a(n, 0), p(n, 0);
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) cin >> p[i];
    vector tr(n + 1, 0);
    auto lowbit = [&] (int x) -> int {
        return x & -x;
    };
    auto add = [&] (int x, int v) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
    };
    std::function<int (int)> query = [&] (int x) -> int {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    };
    auto findl = [&] (int x) -> int {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (p[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return r;
    };
    auto findr = [&] (int x) -> int {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (p[mid] <= x) l = mid;
            else r = mid - 1;
        }
        return l;
    };
    sort(p.begin(), p.end(), [&] (int a, int b) {return a < b;});
    for (int i = 0; i < n; i ++) {
        add(i + 1, 1);
    }
    for (int i = 0; i < n; i ++) {
        int now = 0;
        for (int j = 29; j >= 0; j --) {
            int l = now + (1 << j) * ((a[i] >> j) & 1);
            int r = l + (1 << j) - 1;
            int fl = findl(l), fr = findr(r);
            if (query(fr + 1) - query(fl) <= 0 || p[fr] > r || p[fl] < l) now += ((1 << j) * (!((a[i] >> j) & 1)));
            else now += (1 << j) * ((a[i] >> j) & 1);
        }
        add(findl(now) + 1, -1);
        cout << (now ^ a[i]) << " ";
    }
    return 0;
}

#endif

/*

*/
