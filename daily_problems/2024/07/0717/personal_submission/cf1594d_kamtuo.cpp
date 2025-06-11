/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-17 11:59 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N =  212345;

int main() {
    int t;
    cin >> t;
    while (t --) {
        int n, m;
        cin >> n >> m;
        vector<bool> st(n + 1, false);
        vector<int> in(n + 1, false);
        int idx = 1;
        vector<int> ans1(n + 1, 0), ans0(n + 1, 0), ne((m + 1) << 1, 0), h(n + 1, 0), d((m + 1) << 1, 0), w((m + 1) << 1, 0);
        auto add = [&] (int u, int v, int e) {
            ne[idx] = h[u];
            d[idx] = v;
            w[idx] = e;
            h[u] = idx ++;
        };
        for (int i = 1; i <= m; i ++) {
            int u, v;
            string s;
            int e;
            cin >> u >> v >> s; 
            if (s == "crewmate") e = 0;
            else e = 1;
            add(u, v, e);
            add(v, u, e);
        } 
        bool ok = true;
        std::function<int (int, int, int)> dfs = [&] (int now, int flag, int fa) {
            int res = flag;
            in[now] = flag;
            st[now] = true;
            for (int i = h[now]; i; i = ne[i]) {
                int j = d[i];
                // cout << j << endl;
                if (st[j] && in[j] != flag ^ w[i]) ok = false;
                if (st[j]) continue;
                res += dfs(j, flag ^ w[i], now);
            }
            return res;
        };
        for (int i = 1; i <= n; i ++) {
            if (st[i] == false) {
                ans0[i] = dfs(i, 0, -1);
            }
        }
        for (int i = 1; i <= n; i ++) {
            st[i] = false;
        }
        for (int i = 1; i <= n; i ++) {
            if (st[i] == false) {
                ans1[i] = dfs(i, 1, -1);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            ans += max(ans1[i], ans0[i]);
        }
        if (!ok) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}

/*

*/
