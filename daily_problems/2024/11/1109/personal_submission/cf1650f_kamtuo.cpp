/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-09 19:23 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    struct Node {
        int i;
        int t, p;
    };
    for (int _ = 1; _ <= t; _ ++) {
        int n, m;
        cin >> n >> m;
        vector bag(n + 1, vector<Node> ());
        vector a(n + 1, 0);
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i ++) {
            int e, t, p;
            cin >> e >> t >> p;
            bag[e].push_back({i, t, p});
        }
        bool ok = false;
        int now = 0;
        vector<int> ans;
        for (int i = 1; i <= n; i ++) {
            if (bag[i].size() == 0 || now >= a[i]) {
                ok = true;
                break;
            }
            vector dp(bag[i].size() + 1, vector (123, 0x3f3f3f3f));
            vector used(bag[i].size() + 1, vector (123, -1));
            dp[0][0] = 0;
            used[0][0] = 0;
            for (int j = 1; j <= bag[i].size(); j ++) {
                dp[j][0] = dp[j - 1][0];
                used[j][0] = 0;
                for (int k = 1; k <= 100; k ++) {
                    dp[j][k] = dp[j - 1][k];
                    used[j][k] = used[j - 1][k];
                    if (used[j - 1][max(k - bag[i][j - 1].p, 0)] != -1) {
                        if (dp[j][k] > dp[j - 1][max(k - bag[i][j - 1].p, 0)] + bag[i][j - 1].t) {
                            used[j][k] = j;
                            dp[j][k] = dp[j - 1][max(k - bag[i][j - 1].p, 0)] + bag[i][j - 1].t;
                        } 
                    }
                }
            }
            if (used[bag[i].size()][100] == -1) ok = true;
            else {
                now += dp[bag[i].size()][100];
                if (now > a[i]) ok = true;
                int u = bag[i].size();
                int v = 100;
                while (used[u][v] != 0) {
                    // debug("use:", used[u][v]);
                    ans.push_back(bag[i][used[u][v] - 1].i);
                    int f = v;
                    v -= bag[i][used[u][v] - 1].p;
                    v = max(v, 0);
                    u = used[u][f] - 1;
                }
            }
        }
        if (ok) cout << -1 << "\n";
        else {
            cout << ans.size() << "\n";
            for (int i = 0; i < ans.size(); i ++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

#endif

/*

*/
