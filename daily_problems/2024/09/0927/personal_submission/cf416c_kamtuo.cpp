/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-27 09:50 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    struct Node {
        int r;
        int i;
        bool operator < (const Node &now) const {
            return r < now.r;
        }
    };
    cin >> n;
    vector c(n, 0), p(n, 0);
    for (int i = 0; i < n; i ++) cin >> c[i] >> p[i];
    int k;
    cin >> k;
    vector<Node> table(k);
    for (int i = 0; i < k; i ++) {
        cin >> table[i].r;
        table[i].i = i;
    }
    vector<std::pair<int, int>> ans;
    int tot = 0;
    sort(table.begin(), table.end());
    vector used(k, 0), st(n, 0);
    for (int i = 0; i < n; i ++) {
        int v = -1;
        for (int j = 0; j < n; j ++) {
            if (st[j]) continue;
            if (v == -1) {
                v = j;
            } else {
                if (p[v] < p[j]) v = j;
                else if (p[v] == p[j]) if (c[v] > c[j]) v = j;
            }
        }
        // debug("v:", v);
        st[v] = 1;
        int now = -1;
        for (int j = 0; j < k; j ++) {
            if (table[j].r >= c[v] && used[table[j].i] == 0) {
                now = table[j].i;
                break;
            } 
        }
        if (now != -1) {
            used[now] = 1;
            tot += p[v];
            ans.push_back({v + 1, now + 1});
        }
    }
    cout << ans.size() << ' ' << tot << "\n";
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i].first << ' ' << ans[i].second << "\n";
    }
    return 0;
}

#endif

/*

*/
