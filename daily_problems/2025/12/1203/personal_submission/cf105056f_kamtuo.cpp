/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-12-03 22:28                         */
/* Software : Visual Studio Code                            */
/*                                                          */
/*  ██╗  ██╗ █████╗ ███╗   ███╗████████╗██╗   ██╗ ██████╗   */
/*  ██║ ██╔╝██╔══██╗████╗ ████║╚══██╔══╝██║   ██║██╔═══██╗  */
/*  █████╔╝ ███████║██╔████╔██║   ██║   ██║   ██║██║   ██║  */
/*  ██╔═██╗ ██╔══██║██║╚██╔╝██║   ██║   ██║   ██║██║   ██║  */
/*  ██║  ██╗██║  ██║██║ ╚═╝ ██║   ██║   ╚██████╔╝╚██████╔╝  */
/*  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝   ╚═╝    ╚═════╝  ╚═════╝   */
/*----------------------------------------------------------*/

#ifndef KAMTUO_LEETCODE


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, q;
    cin >> n >> k >> q;
    const int M = 123456;
    vector pr(M, 0), st(M, 0);
    int psum = 0;
    vector to(n + 1, vector<int> ());
    int mod = k;
    map<int, int> mp;
    std::function<int(int, int)> gcd = [&] (int a, int b) -> int {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    if (k == 1) {
        for (int i = 1; i <= n; i ++) cout << 0 << ' ';
        return 0;
    }
    // vector<int> pr;
    struct Node {
        int num;
        int val;
        bool operator < (const Node &now) const {
            return val < now.val;
        };
    };
    vector<vector<Node>> a(n + 1);
    vector<int> vv(n + 1);
    for (int i = 1; i <= n; i ++) {
        a[i].push_back({1, 0});
        cin >> vv[i];
    }
    for (int i = 2; i <= n; i ++) {
        int p;
        cin >> p;
        to[p].push_back(i);
    }
    std::function<vector<Node> (vector<Node>)> cal = [&] (vector<Node> now) -> vector<Node> {
        vector<Node> r;
        int s = mod;
        // for (int i = 0)
        for (int i = 0; i < now.size(); i ++) {
            if (gcd(now[i].num, s) != 1 || now[i].val == 0) {
                r.push_back(now[i]);
                s /= gcd(now[i].num, s);
            }
        }
        // mp2.clear();
        return r;
    };
    for (int i = 1; i <= q; i ++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back({gcd(mod, v), i});
    }
    vector ans(n + 1, -1);
    std::function<void(int)> dfs = [&] (int u) {
        int res = vv[u];
        sort(a[u].begin(), a[u].end());
        a[u] = cal(a[u]);
        for (int i = 0; i < a[u].size(); i ++) {
            if (1ll * a[u][i].num * res % mod == 0) {
                ans[u] = a[u][i].val;
                // cout << res << "\n";
                break;
            }
            res = a[u][i].num * 1ll * res % mod;
        }
        for (int i = 0; i < to[u].size(); i ++) {
            for (int j = 0; j < a[u].size(); j ++) {
                if (a[u][j].val > 0) {
                    // if (gcd(a[u][j].num, mod) != 1)
                    a[to[u][i]].push_back(a[u][j]);
                }
            }
            dfs(to[u][i]);
        }
        // dfs(1);
    };
    dfs(1);
    for (int i = 1; i <= n; i ++) cout << ans[i] << " ";
    return 0;
}

#endif

/*

*/
