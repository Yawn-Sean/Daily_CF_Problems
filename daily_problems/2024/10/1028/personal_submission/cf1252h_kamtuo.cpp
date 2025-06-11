/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-28 08:51 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    struct Node {
        int l, s;
    };
    vector<Node> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i].l >> a[i].s;
        if (a[i].l > a[i].s) std::swap(a[i].l, a[i].s);
    }
    LL ans = 0;
    sort(a.begin(), a.end(), [&] (Node x, Node y) {if (x.l != y.l ) return x.l < y.l; return x.s < y.s;});
    vector maxl(n + 1, 0);
    maxl[n - 1] = 0;
    for (int i = n - 2; i >= 0; i --) {
        maxl[i] = max(maxl[i + 1], a[i + 1].s);
    }
    for (int i = 0; i < n; i ++) {
        int now = a[i].l;
        ans = max(1ll * a[i].l * a[i].s, ans);
        ans = max(2ll * now * min(a[i].s, maxl[i]), ans);
    }
    if (ans % 2) {
        cout << ans / 2 << ".5\n";
    } else {
        cout << ans / 2 << ".0\n";
    }
    // printf("\n", ans);
    return 0;
}

#endif

/*

*/
