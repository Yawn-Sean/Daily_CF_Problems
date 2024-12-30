/*
每个结点的 c[i] < sz[i]
假如所有叶子结点的值都确定了，那么能否一次性确定其他结点的值？
2000 个点，1e9 的值域，是否可以随机生成叶子，然后往上构造出整个树？
*/

int T;
mt19937 rd(time(NULL));
int n, c[N], root, a[N];
vector<int> values[N];
vector<int> e[N];
bool ok = true;

void dfs(int u) {
    for (auto &v : e[u]) {
        dfs(v);
        for (int i = 0; i < values[v].size(); i++) {
            values[u].pb(values[v][i]);
        }
        if (!ok) {
            return;
        }
    }
    if (!ok) {
        return;
    }

    sort(values[u].begin(), values[u].end());
    if (c[u] > values[u].size()) {
        ok = false;
        return;
    }
    if (values[u].size() == 0) {
        int val1 = 1, val2 = 1e9;
        a[u] = rd() % (val2 - val1 + 1) + val1;
        values[u].pb(a[u]);
        return;
    }

    int val1 = (c[u] - 1 >= 0 ? values[u][c[u] - 1] : 1);
    int val2 = (c[u] >= values[u].size() ? 1e9 : values[u][c[u]]);
    val1++;
    a[u] = (val1 + val2) / 2;
    values[u].pb(a[u]);
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p >> c[i];
        if (p == 0) {
            root = i;
        } else {
            e[p].pb(i);
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= n; j++) {
            values[j].clear();
        }
        ok = true;
        dfs(root);
        if (ok) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
            return;
        } 
    }

    cout << "NO\n";
}          