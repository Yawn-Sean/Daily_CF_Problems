/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-03 10:30 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<string> mp(n);
    vector dp(n + 1, vector (n + 1, 0));
    for (int i = 0; i < n; i ++) cin >> mp[i];
    struct Node {
        int x, y;
        int cnt;
    };
    vector<Node> q;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (mp[i - 1][j - 1] == 'a') dp[i][j] ++;    
        }
    }
    int pre = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i - 1 + j - dp[i][j] <= k) pre = max(pre, i - 1 + j);
        }
    }
    vector st(n, vector(n, 0));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i - 1 + j - dp[i][j] <= k && i - 1 + j == pre) {
                q.push_back({i - 1, j - 1, 0});
                st[i - 1][j - 1] = 1;
            } 
        }
    }
    string ans;
    if (k == 0) {
        q.clear();
        q.push_back({0, 0, mp[0][0] - 'a'});
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                st[i][j] = 0;
            }
        }
        st[0][0] = 1;
    } else {
        for (int i = 0; i < pre - 1; i ++) {
            ans.push_back('a');
        }
    }
    while (q.size()) {
        vector<Node> now;
        int to = 30;
        for (int i = 0; i < q.size(); i ++) {
            to = min(to, q[i].cnt);
        }
        ans.push_back((char)(to + 'a'));
        for (int i = 0; i < q.size(); i ++) {
            if (to == q[i].cnt) {
                int x = q[i].x, y = q[i].y;
                if (x + 1 < n && st[x + 1][y] == 0) now.push_back({x + 1, y, mp[x + 1][y] - 'a'});
                if (x + 1 < n) st[x + 1][y] = 1;
                if (y + 1 < n && st[x][y + 1] == 0) now.push_back({x, y + 1, mp[x][y + 1] - 'a'});
                if (y + 1 < n) st[x][y + 1] = 1;
            }
        }
        q = now;
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
