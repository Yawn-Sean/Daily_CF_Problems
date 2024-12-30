/*
先从 1 开始连，可能是 1 3 5 或者 1 5 3
我们看下 3 和 5 后面分别是什么
如果 3 后面有 5，则说明 3 在前，5 在后
如果 5 后面有 3，则说明 5 在前，3 在后
注意不要连重复了，且满了就退出
*/

int T;
PII a[N];
int n;
vector<int> res;
bool vis[N];

void dfs(int u) {
    if (res.size() == n) {
        return;
    }
    res.pb(u);
    vis[u] = true;
    int v1 = a[u].x, v2 = a[u].y;
    if ((a[v1].x == v2 || a[v1].y == v2) && !vis[v1]) {
        dfs(v1);
    } else {
        dfs(v2);
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    dfs(1);
    for (auto v : res) {
        cout << v << " ";
    }
}  