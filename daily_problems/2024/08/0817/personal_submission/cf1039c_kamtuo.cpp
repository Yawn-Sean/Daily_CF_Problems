/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-20 09:36 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    const int N = n + 1, M = m, MOD = 1e9 + 7;
    vector c(N, 0ll), nums(M, 0ll);
    vector two(N, 0);
    two[0] = 1;
    for (int i = 1; i <= n; i ++) two[i] = 2ll * two[i - 1] % MOD;
    struct Node {
        LL u, v;
    };
    vector e(M, (Node){0, 0});
    for (int i = 0; i < n; i ++) cin >> c[i];
    for (int i = 0; i < m; i ++) {
        cin >> e[i].u >> e[i].v;
        e[i].u --;
        e[i].v --;
        nums[i] = c[e[i].u] ^ c[e[i].v];
    }
    sort(nums.begin(), nums.end());
    int len = unique(nums.begin(), nums.end()) - nums.begin();
    auto find = [&] (LL x) -> int {
        return lower_bound(nums.begin(), nums.begin() + len, x) - nums.begin(); 
    };
    vector x(len + 1, vector<int> ());
    for (int i = 0; i < m; i ++) {
        int fi = find(c[e[i].u] ^ c[e[i].v]);
        x[fi].push_back(i);
    }
    vector edge(N, vector<int> ());
    vector st(N, 0);
    std::function<void (int)> dfs = [&] (int now) {
        if (st[now] == 1) return;
        st[now] = 1;
        for (int i = 0; i < edge[now].size(); i ++) {
            dfs(edge[now][i]);
        }
    };
    LL ans = 0;
    // debug("nums:", nums);
    for (int i = 0; i < len; i ++) {
        int cnt = 0;
        map<int, int> mp;
        for (int j = 0; j < x[i].size(); j ++) {
            int u = e[x[i][j]].u, v = e[x[i][j]].v;
            mp[u] ++;
            mp[v] ++;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int res = 0;
        for (int j = 0; j < x[i].size(); j ++) {
            int u = e[x[i][j]].u, v = e[x[i][j]].v;
            if (st[u] == 0) {
                res ++;
                dfs(u);
            }
        }
        for (int j = 0; j < x[i].size(); j ++) {
            int u = e[x[i][j]].u, v = e[x[i][j]].v;
            st[u] = st[v] = 0;
            edge[u].clear();
            edge[v].clear();
        }
        ans += two[res + n - mp.size()];
        ans %= MOD;
    }
    cout << (ans + ((1ll << k) - len) % MOD * two[n] % MOD) % MOD << endl;
    return 0;
}

#endif

/*

*/
