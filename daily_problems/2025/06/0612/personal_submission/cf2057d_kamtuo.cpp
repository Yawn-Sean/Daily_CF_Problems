/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-06-12 15:56                         */
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
    struct Node {
        int l, r;
        int maxa_, mina_, maxa, mina;
        int ans;
    };
    const int N = 223456;
    vector<Node> tr(N << 2);
    vector a(N, 0);
    auto pushup = [&] (int u) {
        tr[u].mina = min(tr[u << 1].mina, tr[u << 1 | 1].mina);
        tr[u].mina_ = min(tr[u << 1].mina_, tr[u << 1 | 1].mina_);
        tr[u].maxa = max(tr[u << 1].maxa, tr[u << 1 | 1].maxa);
        tr[u].maxa_ = max(tr[u << 1].maxa_, tr[u << 1 | 1].maxa_);
        tr[u].ans = max(tr[u << 1].ans, tr[u << 1 |1].ans);
        tr[u].ans = max(tr[u].ans, tr[u << 1].maxa - tr[u << 1 | 1].mina);
        tr[u].ans = max(tr[u].ans, tr[u << 1 | 1].maxa_ - tr[u << 1].mina_);
    };
    std::function<void(int, int, int)> build = [&] (int u, int l, int r) {
        if (l == r) {
            tr[u] = {l, r, a[l] - l, a[l] - l, a[r] + r, a[r] + r, 0};
            return;
        }
        int mid = l + r >> 1;
        tr[u] = {l, r};
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    };
    std::function<void (int, int, int)> add = [&] (int u, int l, int x) {
        if (tr[u].l == tr[u].r) {
            tr[u].mina = tr[u].maxa = x + tr[u].l;
            tr[u].mina_ = tr[u].maxa_ = x - tr[u].r;
            tr[u].ans = 0;
            return;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) add(u << 1, l, x);
        else add(u << 1 | 1, l, x);
        pushup(u);
    };
    cin >> t;
    while (t --) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        build(1, 1, n);
        cout << tr[1].ans << "\n";
        for (int i = 1; i <= q; i ++) {
            int pos, x;
            cin >> pos >> x;
            a[pos] = x;
            add(1, pos, x);
            cout << tr[1].ans << "\n";
        }
    }
    return 0;
}

#endif

/*

*/
