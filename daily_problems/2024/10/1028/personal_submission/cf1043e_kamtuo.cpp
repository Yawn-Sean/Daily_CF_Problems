/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-28 09:58 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector s(n + 1, 0ll);
    struct Node {
        int x, y;
        int i;
    };
    vector<Node> a(n);
    vector ans(n, 0ll);
    for (int i = 0; i < n; i ++) {
        cin >> a[i].x >> a[i].y;
        a[i].i = i;
    }
    for (int i = 0; i < m; i ++) {
        int xa, ya;
        cin >> xa >> ya;
        xa --, ya --;
        if (a[xa].x + a[ya].y < a[xa].y + a[ya].x) ans[xa] -= a[xa].x + a[ya].y, ans[ya] -= a[xa].x + a[ya].y;
        else ans[xa] -= a[xa].y + a[ya].x, ans[ya] -= a[xa].y + a[ya].x;
    }
    sort(a.begin(), a.end(), [] (Node x, Node y) {return x.x - x.y < y.x - y.y;});
    for (int i = 0; i < n; i ++) {
        ans[a[i].i] += 1ll * i * a[i].y + 1ll * (n - i - 1) * a[i].x;
        s[1] += a[i].y, s[i + 1] -= a[i].y;
        if (i + 2 <= n) s[i + 2] += a[i].x;
    }
    for (int i = 1; i <= n; i ++) s[i] += s[i - 1];
    for (int i = 1; i <= n; i ++) {
        ans[a[i - 1].i] += s[i];
    }
    for (int i = 0; i < n; i ++) cout << ans[i] << ' ';
    return 0;
}

#endif

/*

*/
