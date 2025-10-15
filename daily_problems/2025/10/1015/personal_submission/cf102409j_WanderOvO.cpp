/*
无自环，但是可能有重边，可能需要先去掉重边
只要一条边的两个端点的值不一样就好
如果所有点的初始值都相等，有机会吗？
这个时候无论怎么选集合和 x，都只能让图中出现两种不同的值，所以必须得是二分图才行
对于所有边
- 假如其两个端点值相等，则必须恰好选一个点去改变值，因为不选或者选两个都还会一样
- 假如其两个端点的值本来就不相等，则可能都不选，可能都选，可能只选一个
  其中，都不选和都选 100% 能保证操作之后这条边的端点值仍然不同，只选一个可能会导致相等
  为什么可能会被选？因为这个点还连着其他边呢
假如有一个三元环，三个点的值都相等，则必不可能使这些边满足题意
如果是 5 元环呢？也不行，值相同的奇数元环都不可以
二分图是根本没有奇数元环，所以一定能做到，给定的值域 > 点数，不会操作之后还撞值
我们把所有值相同的边保留下来，单独再建一个图，这个图必须得是二分图，否则不用管了
之后，我们只考虑二分图中被染色成 0 的点，我们只对这些点做异或
假设某个这样的点是 u，考虑 u 的邻点（全图中的），把 u 不能异或的那些值算出来，从备选集合中删掉
*/ 

int n, m, a[N], color[N];
vector<vector<int>> e(N);
vector<vector<int>> equal_e(N);
set<LL> exist_edge;
bool two_part = true;
int candidate_colors[M];

void dfs(int u, int c) {
    color[u] = c;
    for (auto v : equal_e[u]) {
        if (color[v] == -1) {
            dfs(v, 1 - c);
        } else {
            if (color[v] == color[u]) {
                two_part = false;
                return;
            }
        }
    }
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        LL u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        if (a[u] == a[v]) {
            equal_e[u].push_back(v);
            equal_e[v].push_back(u);
        }
    }

    memset(color, -1, sizeof color);
    for (int i = 1; i <= n; i++) {
        if (color[i] < 0) {
            dfs(i, 0);
        }
    }

    if (!two_part) {
        cout << "-1\n";
        return;
    }

    vector<int> candidate_nodes;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            candidate_nodes.push_back(i);
            for (auto v : e[i]) {
                candidate_colors[a[v] ^ a[i]] = 1;
            }
        }
    }

    // assert(candidate_colors.size() > 0);
    int x = -1;
    for (int i = 0; i < M; i++) {
        if (candidate_colors[i] == 0) {
            x = i;
            break;
        }
    }
    cout << candidate_nodes.size() << " " << x << "\n";
    for (auto v : candidate_nodes) {
        cout << v << " ";
    }

    for (auto v : candidate_nodes) {
        a[v] ^= x;
    }
    for (int i = 1; i <= n; i++) {
        for (auto v : e[i]) {
            if (a[i] == a[v]) {
                exit(1);
            }
        }
    }
}   
