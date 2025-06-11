/*
本质上就是把 a 数组中的 x 全都变成 y，使得代价最小
对于每个 x，考虑其相邻的数 y，假设 x != y 则存起来
显然，由于每个数至多只有两个邻居，所以每个数至多出现两次
显然，对于某个 x 相邻的其他所有 y，把 x 调整到中位数位置最好
*/

int T;
LL n, a[N], m;
vector<vector<LL>> adj(N);

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= m; i++) {
        LL val = a[i];
        if (i + 1 <= m) {
            if (a[i] != a[i + 1]) {
                adj[val].pb(a[i + 1]);
            }
        }
        if (i - 1 > 0) {
            if (a[i] != a[i - 1]) {
                adj[val].pb(a[i - 1]);
            }
        }
    }

    map<LL, LL> sum;
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        for (int j = 0; j < adj[i].size(); j++) {
            sum[i] += abs(adj[i][j] - i);
        }
    }
    
    LL res_base = 0;
    for (int i = 1; i < m; i++) {
        res_base += abs(a[i + 1] - a[i]);
    }
    LL res = res_base;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 0) {
            LL new_res = res_base - sum[i];
            LL sz = adj[i].size();
            LL mid_val = adj[i][sz / 2];
            for (auto val : adj[i]) {
                new_res += abs(val - mid_val);
            }
            res = min(res, new_res);
        }
    }
    cout << res << "\n";
}       
