/*
用并查集 merge i 和 a[i]，则有几个集合就至多有几个环
最少环则要看有多少个自己就确定成环的，比如有 >= 3 个点且循环了一遍，这个可以 dfs 检查，强制只往某个方向走
所有不满足上面条件的，都可以拼起来组成一个环
*/

int fa[N], n, a[N], sz[N], vis[N];
int must_be_cnt = 0, other_cnt = 0;
vector<vector<int>> e(N);

int find(int x) {
    if (x == fa[x]) {
        return fa[x];
    }
    return fa[x] = find(fa[x]);
}

bool together(int x, int y) {
    return find(x) == find(y);
}

void merge(int x, int y) {
    if (together(x, y)) return;

    x = find(x);
    y = find(y);
    fa[x] = y;
    sz[y] += sz[x];
}

bool dfs(int u, int fa) {
    vis[u] = true;
    bool res = false;
    for (auto v : e[u]) {
        if (v != fa) {
            if (vis[v]) {
                return true;
            } else {
                res = (res || dfs(v, u));
            }
            break;
        }
    }
    return res;
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        sz[i] = 1;
        fa[i] = i;
        vis[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        merge(i, a[i]);
        e[a[i]].push_back(i);
        e[i].push_back(a[i]);
    }

    must_be_cnt = 0;
    other_cnt = 0;
    for (int i = 1; i <= n; i++) {
        find(i);
        if (i == fa[i]) {
            if (sz[i] <= 2) {
                other_cnt++;
            } else {
                if (dfs(i, 0)) {
                    must_be_cnt++;
                } else {
                    other_cnt++;
                }
            }
        }
    }

    cout << must_be_cnt + (other_cnt > 0 ? 1 : 0) << " ";

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (i == find(i)) {
            mx++;
        }
    }

    cout << mx << "\n";
}
