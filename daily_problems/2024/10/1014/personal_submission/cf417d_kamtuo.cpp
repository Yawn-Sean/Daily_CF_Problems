/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-14 19:46 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, b;
    cin >> n >> m >> b;
    const LL MAX = 1ll * 0x3f3f3f3f3f3f3f3f;
    struct Node {
        LL x, k, num;
        bool operator < (const Node &now) const {
            return k < now.k;
        };
    };
    vector<Node> node(n, {0, 0, 0});
    for (int i = 0; i < n; i ++) {
        cin >> node[i].x >> node[i].k;
        int now;
        cin >> now;
        for (int j = 0; j < now; j ++) {
            int cn;
            cin >> cn;
            node[i].num |= (1 << (cn - 1));
        }
    }
    sort(node.begin(), node.end());
    LL ans = MAX;
    vector dp((1 << m), 1ll * MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < (1 << m); j ++) {
            dp[j | node[i].num] = min(dp[j | node[i].num], dp[j] + node[i].x);
        }
        ans = min(ans, dp[(1 << m) - 1] + 1ll * b * node[i].k);
    } 
    if (ans != MAX) cout << ans << "\n";
    else cout << -1 << "\n";
    return 0;
}

#endif

/*

*/
