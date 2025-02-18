/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-16 14:56 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector r(n + 1, 0), l(n + 1, 0);
    vector tr(2, vector (n + 1, 0));
    auto lowbit = [&] (int x) -> int {
        return x & -x;
    };
    auto add = [&] (int x, int val, int tag) {
        for (int i = x; i <= n; i += lowbit(i)) tr[tag][i] += val;
    };
    auto query = [&] (int x, int tag) -> int {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[tag][i];
        return res;
    };
    for (int i = 1; i <= n; i ++) {
        cin >> r[i];
        r[i] %= 2;
        add(i, r[i], 0);
    }
    for (int i = 1; i <= n; i ++) {
        cin >> l[i];
        l[i] %= 2;
        add(i, l[i], 1);
    }
    auto find = [&] (int x, int y, int tag) -> int {
        int now = query(y, tag) - query(x - 1, tag);
        // debug("tag:", tag, x, y, now);
        if (now == y - x + 1) return 1;
        else if (now == 0) return 0;
        return -1;
    };
    for (int i = 1; i <= q; i ++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) std::swap(x1, x2);
        if (y1 > y2) std::swap(y1, y2);
        int now = r[x1];
        // debug("finx1, x2:", find(x1, x2, 0));
        // debug("finy1, y2:", find(y1, y2, 1));
        // debug("now:", now);
        if (find(x1, x2, 0) == now && find(y1, y2, 1) == now) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

#endif

/*

*/
