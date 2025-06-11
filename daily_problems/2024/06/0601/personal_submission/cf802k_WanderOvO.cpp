/*
限制每个结点访问不超过 k 次，则至多访问其 k 个子树
如果还想递归回去，则至多访问 k - 1 个子树
如果以 u 为根的子树中有不超过 k - 1 个子树，则都可以访问，否则要考虑拿其中最大的一些
还要考虑是否从 u 子树中退出来
dp[u][0/1]: 访问 u 子树每个结点不超过 k 次，最终停在 u 子树里面/能退出 u 子树的最大权值
dp[u][0] 需要停留在里面
- 停留在 u 点的某个儿子处：dp[u][0] = (dp[v][1] + w(u, v)) 最大的 k 个子树的和
- 停留在更小的子树中：在上一个方案的基础上，看能否把某个 dp[v][1] 替换成 dp[x][0]
  如果是把 dp[v][1] 替换成 dp[v][0]，则需要 dp[v][0] > dp[v][1]
  如果是把 dp[v][1] 替换成 dp[x][0]，则需要 x != 任何一个已经选的 v，且 dp[v][1] 是已选中最小的
dp[u][1] 需要成功退出，所以只能访问 k - 1 个子树，并且都得能推出来
- dp[u][1] = (dp[v][1] + w(u, v)) 最大的 k - 1 个子树的和
*/

int T;
vector<PII> e[N];
int n, k, dp[N][2];

void dfs(int u, int fa) {
    vector<PII> candidates0, candidates1;
    vector<PII> tmp;
    for (auto &edge : e[u]) {
        int v = edge.x, w = edge.y;
        if (v != fa) {
            dfs(v, u);
            candidates0.pb({dp[v][0] + w, v});
            candidates1.pb({dp[v][1] + w, v});
            tmp.pb({dp[v][1] + w, v});
        }  
    }
    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());
    dp[u][0] = 0;
    dp[u][1] = 0;
    if (tmp.size() > 0) {
        // 能返回到 u，则只能访问最大的 k - 1 个子树 
        for (int i = 0; i < min((int)tmp.size(), k - 1); i++) {
            dp[u][1] += tmp[i].x;
        }
        // 返回不到 u，则是最大的 k 个子树，且至多有一个子树也是不返回的
        set<int> top_k;
        for (int i = 0; i < min((int)tmp.size(), k); i++) {
            dp[u][0] += tmp[i].x;
            top_k.insert(tmp[i].y);
        }
        // 考虑把某个能返回的 v 改成不能返回的 v
        int max_change = -1e9;
        int last = min((int)tmp.size() - 1, k - 1);
        PII mn = tmp[last];
        for (int i = 0; i < (int)candidates0.size(); i++) {
            int v = candidates0[i].y, w_new = candidates0[i].x, w_old = candidates1[i].x;
            if (top_k.count(v)) {
                max_change = max(max_change, w_new - w_old);
            } else {
                max_change = max(max_change, w_new - mn.x);
            }
        }
        dp[u][0] += max_change;
    }
}

void solve1() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        e[u].pb({v, c});
        e[v].pb({u, c});
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << "\n";
}                 