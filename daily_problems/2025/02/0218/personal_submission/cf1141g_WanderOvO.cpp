/*
有一棵树，需要把树上每条边染一种颜色，假如一个点的所有边的颜色都不一样则这个点是好的
问至少需要多少种颜色，才能使得不超过 k 个点是**不好的**
度最大的点的度为 d，则 d 种颜色一定可以保证所有点都是好的
假设最少需要 r 种颜色，则所有度 > r 的点自然是不好的，所有度 <= r 的点一定好吗？是的，一定有办法这样去规划
把所有点的度拿出来，排序，然后看 r 为多少时，> r 的只有 <= k 个
然后从 1 开始遍历，假如当前点为 u，u 的父亲 fa 连过来的边的颜色是 c
如果 d[u] > r，则 u 的所有边连同一种颜色就好了，无所谓
如果 d[u] < r，则枚举邻点的同时枚举还没用的颜色，继续往下做
*/

struct Edge {
    int u, v, id;
};

vector<vector<Edge>> e(N); 
int d[N], n, k, cnt[N];
int res[N], r = 0;

void dfs(int u, int fa, int c) {
    if (d[u] > r) {
        for (auto edge : e[u]) {
            int v = edge.v, id = edge.id;
            if (v != fa) {
                res[id] = 1;
                dfs(v, u, 1);
            }
        }
    } else {
        int color = 1;
        for (auto edge : e[u]) {
            int v = edge.v, id = edge.id;
            if (v != fa) {
                if (color == c) {
                    color++;
                }
                res[id] = color;
                dfs(v, u, color);
                color++;
            }
        }
    }
}

void meibao() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        Edge edge, redge;
        cin >> edge.u >> edge.v;
        edge.id = i;
        redge.u = edge.v;
        redge.v = edge.u;
        redge.id = i;
        e[edge.u].push_back(edge);
        e[edge.v].push_back(redge);
        d[edge.u]++;
        d[edge.v]++;
    }

    for (int i = 1; i <= n; i++) {
        cnt[d[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = 0; i <= n; i++) {
        if (cnt[n] - cnt[i] <= k) {
            r = i;
            break;
        }
    }

    dfs(1, 0, 0);

    cout << r << "\n";
    for (int i = 1; i < n; i++) {
        cout << res[i] << " ";
    }
}
