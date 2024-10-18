/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-23 20:07 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int MAX = 0x3f3f3f3f;
    int n, m;
    cin >> n >> m;
    string mp[2];
    cin >> mp[0] >> mp[1];
    struct Node {
        int l, r;
        vector<vector<int>> to;
    };
    vector<Node> tr((n + 1) << 2);
    vector a(n + 1, vector (2, vector (2, 0)));
    for (int i = 0; i < n; i ++) {
        if (mp[0][i] == '.') {
            if (mp[1][i] == 'X') {
                a[i + 1][0][0] = 0;
                a[i + 1][0][1] = MAX;
                a[i + 1][1][0] = MAX;
                a[i + 1][1][1] = MAX;
            } else {
                a[i + 1][0][0] = 0;
                a[i + 1][0][1] = 1;
                a[i + 1][1][0] = 1;
                a[i + 1][1][1] = 0;
            }
        } else {
            if (mp[1][i] == 'X') {
                a[i + 1][0][0] = MAX;
                a[i + 1][0][1] = MAX;
                a[i + 1][1][0] = MAX;
                a[i + 1][1][1] = MAX;
            } else {
                a[i + 1][0][0] = MAX;
                a[i + 1][0][1] = MAX;
                a[i + 1][1][0] = MAX;
                a[i + 1][1][1] = 0;
            }
        }
    }
    auto pushup = [&] (int u) {
        tr[u].to[0][0] = 1 + min(tr[u << 1].to[0][0] + tr[u << 1 | 1].to[0][0], tr[u << 1].to[0][1] + tr[u << 1 | 1].to[1][0]);
        tr[u].to[0][1] = 1 + min(tr[u << 1].to[0][0] + tr[u << 1 | 1].to[0][1], tr[u << 1].to[0][1] + tr[u << 1 | 1].to[1][1]);
        tr[u].to[1][0] = 1 + min(tr[u << 1].to[1][1] + tr[u << 1 | 1].to[1][0], tr[u << 1].to[1][0] + tr[u << 1 | 1].to[0][0]);
        tr[u].to[1][1] = 1 + min(tr[u << 1].to[1][1] + tr[u << 1 | 1].to[1][1], tr[u << 1].to[1][0] + tr[u << 1 | 1].to[0][1]);
        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j < 2; j ++) {
                tr[u].to[i][j] = min(MAX, tr[u].to[i][j]);
            }
        }
    };
    std::function<void (int, int, int)> build = [&] (int u, int l, int r) {
        if (l == r) {
            tr[u] = {l, r, a[l]};
            return;
        }
        vector f(2, vector (2, 0));
        tr[u] = {l, r, f};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    };
    struct ANS {
        int xx, xy, yx, yy;
    };
    std::function< ANS (int, int, int)> query = [&] (int u, int l, int r) -> ANS {
        if (l <= tr[u].l && r >= tr[u].r) {
            return {tr[u].to[0][0], tr[u].to[0][1], tr[u].to[1][0], tr[u].to[1][1]};
        }
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        ANS res = {MAX, MAX, MAX, MAX};
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid && r > mid) {
            ANS x = query(u << 1, l, r);
            ANS y = query(u << 1 | 1, l, r);
            res.xx = min(x.xx + y.xx + 1, x.xy + y.yx + 1);
            res.xy = min(x.xx + y.xy + 1, x.xy + y.yy + 1);
            res.yx = min(x.yx + y.xx + 1, x.yy + y.yx + 1);
            res.yy = min(x.yx + y.xy + 1, x.yy + y.yy + 1);
        } else if (l <= mid) {
            res = query(u << 1, l, r);
        } else if (r > mid) {
            res = query(u << 1 | 1, l, r);
        }
        res.xx = min(MAX, res.xx);
        res.xy = min(MAX, res.xy);
        res.yx = min(MAX, res.yx);
        res.yy = min(MAX, res.yy);
        return res;
    };
    build(1, 1, n);
    for (int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        int s = 0, e = 0;
        if (x > n) s = 1, x -= n;
        if (y > n) e = 1, y -= n;
        if (x > y) std::swap(x, y), std::swap(s, e);
        int now = 0;
        if (s == 0 && e == 0) {
            now = query(1, x, y).xx; 
        } else if (s == 0 && e == 1) {
            now = query(1, x, y).xy;
        } else if (s == 1 && e == 0) {
            now = query(1, x, y).yx;
        } else {
            now = query(1, x, y).yy;
        }
        cout << (now >= MAX ? -1 : now) << "\n";
    }
    return 0;
}

#endif

/*

*/
