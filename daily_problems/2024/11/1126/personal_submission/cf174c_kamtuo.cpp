/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2024-11-26 15:04                         */
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
    vector a(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    struct Node {
        int l, r;
        int mina;
    };
    vector<Node> tr(n << 2 + 1);
    auto pushup = [&] (int u) {
        tr[u].mina = min(tr[u << 1].mina, tr[u << 1 | 1].mina);
    };
    std::function<void (int, int, int)> build = [&] (int u, int l, int r) {
        if (l == r) {
            tr[u] = {l, r, a[l]};
            return;
        }
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    };
    std::function<int (int, int, int)> query = [&] (int u, int l, int r) -> int {
        int res = 0x3f3f3f3f;
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].mina;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) res = min(query(u << 1, l, r), res);
        if (r > mid) res = min(query(u << 1 | 1, l, r), res);
        return res;
    };
    int ans = 0;
    vector<std::pair<int, int>> pi;
    build(1, 1, n);
    std::function<int (int, int, int)> dfs = [&] (int l, int r, int val) -> int {
        // debug("l:", l, "r:", r);
        int minn = 0x3f3f3f3f;
        int now = 0;
        minn = query(1, l, r) - val;
        // debug("minn:", minn);
        for (int i = 1; i <= minn; i ++) pi.push_back({l, r});
        val += minn;
        for (int i = l; i <= r; i ++) {
            if (a[i] - val) {
                int sl = i, sr = r;
                while (sl < sr) {
                    int mid = sl + sr + 1 >> 1;
                    if (query(1, i, mid) - val == 0) sr = mid - 1;
                    else sl = mid;
                }
                dfs(i, sl, val);
                i = sl;
            }
        }
        return minn;
    };
    int now = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == 0) {
            if (now) {
                dfs(now, i - 1, 0);
                now = 0;
            }
        } else {
            if (now == 0) now = i;
        }
    }
    if (now) dfs(now, n, 0);
    cout << pi.size() << "\n";
    for (auto v : pi) {
        cout << v.first << ' ' << v.second << "\n";
    }
    return 0;
}

#endif

/*

*/
