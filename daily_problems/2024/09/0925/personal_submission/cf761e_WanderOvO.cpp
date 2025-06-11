/*
假如一个点连了 5 个其他点，则必然放不下
邻接点不一定离自己距离是 1
每个点至多往自己的上下左右各连一条边
坐标范围特别大，可否每个点和其邻点的距离差距大一些，最好差出一个数量级
注意到坐标绝对值 <= 1e18，2^30 = 1e9
比方说 1 号点作为根，1 的直接孩子们和 1 的距离应该是 1e10
假设 2 是 1 的孩子，则 2 的孩子们离 2 的距离应该是 1e10 / 2
3 是 2 的孩子，则 3 离自己孩子们距离应该是 1e10 / (2^2)
这样似乎能保证不会撞
*/

int n;
vector<vector<int>> e(N);
vector<int> d(N, 0);
bool used[N][4];
vector<PLL> res(N);

void dfs(int u, int fa, int depth) {
    if (u == 1) {
        res[u] = {0, 0};
    }
    int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
    LL len = 1e10;
    for (int i = 0; i < depth; i++) {
        len /= 2;
    }
    for (auto v : e[u]) {
        if (v != fa) {
            for (int i = 0; i < 4; i++) {
                if (!used[u][i]) {
                    used[u][i] = true;
                    used[v][3 - i] = true;
                    res[v] = {res[u].x + dx[i] * len, res[u].y + dy[i] * len};
                    dfs(v, u, depth + 1);
                    break;
                }
            }
        }
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        d[u]++;
        d[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] > 4) {
            cout << "NO\n";
            return;
        }
    }

    dfs(1, 0, 0);
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << res[i].x << " " << res[i].y << "\n";
    }
}                                                                                                                  
