/*
假设存在虚拟结点 0 和 n + 1
0 连向所有点，所有点连向 n + 1
s[i] >= 0，就连 i -> n + 1，边权为 s[i]，意思是把多收到的 s[i] 给流出去
s[i] < 0，就连 0 -> i，边权是 -s[i]，意思是把多输出的给虚拟补充一下
这样，除了超级源点和超级汇点之外，其他的点都是流入多少就流出多少
然后不会了

羊神思路：考虑图上一棵生成树，找一个点开始 dfs，找到叶子，叶子只有父亲往下连的边，所以确定了这条边的流量
然后往上推即可
不在树上的边，都设为 0
*/

struct Edge {
    int v, w, id;
};

vector<vector<Edge>> e(N);
int n, m, s[N], f[N], flow[N];
bool vis[N];

void dfs(int u, int fa, int edge_id) {
    vis[u] = true;
    for (auto edge : e[u]) {
        int v = edge.v, id = edge.id;
        if (!vis[v]) {
            dfs(v, u, id);
        }
    }

    if (edge_id != 0) {
        int d = s[u] - flow[u];
        flow[fa] -= d;
        flow[u] += d;
        if (edge_id > 0) {
            f[edge_id] = d;
        } else {
            f[-edge_id] = -d;
        }
    }
}

void meibao() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        sum += s[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, 0, i});
        e[v].push_back({u, 0, -i});
    }

    if (sum != 0) {
        cout << "Impossible\n";
        return;
    } else {
        cout << "Possible\n";
    }

    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0, 0);
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << f[i] << "\n";
    }
}
