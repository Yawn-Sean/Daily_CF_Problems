/*
从 1 入手，给相邻的所有点的流量 + 边权
题目保证最后得到的图是 DAG，考虑类似拓扑排序的思路
每个点的所有边的流量加起来 / 2 得到出入流量

羊神提示 3： 此时，一定又一个点入流已经被填满了。为什么？

假如所有点的入流都没有被填满，则每个点都得有至少一条来自其他点的入边
恰好有一条时得到的就是外向基环树，有环就矛盾了，所以至少有一个点的入流填满了
如何找到那个填满入流的点？遍历 1 的所有邻点即可。
这个点假如是 v，则 v 的其他未确定的边都是出边，把流量累加到 v 的邻点上，然后看又有谁确定了
看起来很像拓扑排序
*/

struct Edge {
    LL u, v, w;
};

int T;
LL n, m;

void solve1() {
    cin >> n >> m;
    vector<Edge> edges(m + 1);
    unordered_map<LL, int> res;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        res[edges[i].u * N + edges[i].v] = 0;
    }
    vector<vector<Edge>> e(n + 1);
    vector<LL> tot_flow(n + 1, 0), in_flow(n + 1, 0);
    for (int i = 0; i < m; i++) {
        LL u = edges[i].u, v = edges[i].v, w = edges[i].w;
        e[u].pb({u, v, w});
        e[v].pb({v, u, w});
        tot_flow[u] += w;
        tot_flow[v] += w;
    }
    queue<int> q;
    q.push(1);
    vector<bool> vis(n + 1, false);
    while (!q.empty()) {
        LL u = q.front();
        q.pop();
        vis[u] = true;
        for (auto &edge : e[u]) {
            LL v = edge.v, w = edge.w;
            if (vis[v]) continue;
            in_flow[v] += w;
            if (!res.count(u * N + v)) {
                assert(res.count(v * N + u));
                res[v * N + u] = 1;
            }
            if (tot_flow[v] / 2 == in_flow[v] && v != n) {
                q.push(v);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        Edge edge = edges[i];
        LL id = edge.u * N + edge.v;
        cout << res[id] << "\n";
    }
}  
