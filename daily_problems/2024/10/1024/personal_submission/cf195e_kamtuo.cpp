/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-24 18:11 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    const int MOD = 1e9 + 7;
    vector p(n + 1, 0), val(n + 1, 0), to(n + 1, 0), ro(n + 1, 0);
    vector sz(n + 1, 1);
    vector in(n + 1, vector<int> ());
    for (int i = 1; i <= n; i ++) {
        p[i] = i;
        ro[i] = i;
        in[i].push_back(i);
    }
    std::function<int (int)> find = [&] (int x) -> int {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    };
    vector edge(n + 1, vector<int> ());
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j ++) {
            int v, x;
            cin >> v >> x;
            int fv = find(v), fi = find(i);
            edge[i].push_back(ro[fv]);
            ro[fv] = i, ro[fi] = i;
            if (fv - fi) {
                int now = val[v] + to[fv];
                now %= MOD;
                if (sz[fi] >= sz[fv]) {
                    sz[fi] += sz[fv];
                    to[fi] %= MOD;
                    for (int sj = 0; sj < in[fv].size(); sj ++) {
                        val[in[fv][sj]] += (1ll * ((to[fv] + now) % MOD + x) % MOD - to[fi]) % MOD;
                        val[in[fv][sj]] %= MOD;
                        val[in[fv][sj]] += MOD;
                        val[in[fv][sj]] %= MOD;
                        in[fi].push_back(in[fv][sj]);
                    }
                    in[fv].clear();
                    // ro[fv] = ro[fi];
                    p[fv] = fi;
                } else {
                    sz[fv] += sz[fi];
                    to[fv] += ((now + x) % MOD) % MOD;
                    to[fv] %= MOD;
                    for (int sj = 0; sj < in[fi].size(); sj ++) {
                        val[in[fi][sj]] += (to[fi] - to[fv]) % MOD;
                        val[in[fi][sj]] %= MOD;
                        val[in[fi][sj]] += MOD;
                        val[in[fi][sj]] %= MOD;
                        in[fv].push_back(in[fi][sj]);
                    }
                    in[fi].clear();
                    p[fi] = fv;
                }
            }
        }
        int fi = find(i);
        val[i] = - to[fi];
        val[i] %= MOD;
        val[i] += MOD;
        val[i] %= MOD;
        // cout << "val:";
        // for (int _ = 1; _ <= n; _ ++) {
        //     cout << (val[_] + to[find(_)]) % MOD << ' ';
        // }
        // cout << "\n";
    }
    int ans = 0;
    vector st(n + 1, 0);
    std::function<void (int)> dfs = [&] (int now) {
        if (st[now]) return;
        // debug("now:", now);
        st[now] = 1;
        for (auto v : edge[now]) {
            ans += val[v] - val[now]; 
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
            dfs(v);
        }
    };
    for (int i = 1; i <= n; i ++) {
        dfs(ro[find(i)]);
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
