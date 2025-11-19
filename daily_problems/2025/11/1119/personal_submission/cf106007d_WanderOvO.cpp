/*
如果有人能击败 1，则这个点一定要被别人击败才行
对于其他的点，其不能被 1 击败，所以只要能被别人或者 1 号击败即可
如果 a 能击败 b，则连边 a -> b
考虑从 1 开始遍历，我们希望能遍历到全图
因为只要能遍历到全图，说明我们找到了一棵生成树，按照这个生成树从叶子到根(1)的顺序去比赛一定行的
从 1 开始如果不能遍历全图，考虑自己能到的点的集合是 S，不能到的点的集合是 T
我们希望找 u in S，v in T，使得 w[u][v] = '?'
如果有 T 中的点不能被处理，就废了
其实可以更简化一点，1 和 ? 都视为 1，贪心地遍历整个图
*/

int n;
int w[M][M];
int vis[M];
set<int> t;
vector<int> s;
vector<vector<int>> e(M);

void dfs(int u) {
    vis[u] = true;
    s.push_back(u);
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && w[u][v] != 0) {
            e[u].push_back(v);
            dfs(v);
        }
    }
}

void print(int u) {
    for (auto v : e[u]) {
        print(v);
        cout << u << " " << v << "\n";
    }
}

void solve() {   
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '0') {
                w[i][j + 1] = 0;
            } else if (s[j] == '1') {
                w[i][j + 1] = 1;
            } else {
                w[i][j + 1] = -1;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }
    s.clear();
    t.clear();
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    dfs(1);
    
    if (s.size() != n) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        print(1);
    }
    cout << "\n";
}
