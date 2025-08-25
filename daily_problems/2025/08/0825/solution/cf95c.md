**提示 1：** 为了得到 $i$ 出发能到哪里，需要预处理什么？

**提示 2：** 有了上述信息后，我们相当于要解决什么问题？

首先，假设我们目前已经到了 $x$ 位置，接下来能到哪里呢？

我们只需求 $x$ 到任意其他点的最短路，看是否不超过出租车最长使用时间即可。

而一旦知道能到哪里，就可以从这个点出发，往对应的终点连边，边权是该出租车的费用。最后我们在新图中跑一次最短路即可。

时间复杂度为 $\mathcal{O}(n^2\log n+nm)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, m = MII()
    s, t = GMI()
    
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        
        path[u].append(w * n + v)
        path[v].append(w * n + u)
    
    inf = 10 ** 13
    dis = [[inf] * n for _ in range(n)]
    
    def f(d, node):
        return d * n + node
    
    for i in range(n):
        dis[i][i] = 0
        pq = [f(0, i)]
        
        while pq:
            d, u = divmod(heappop(pq), n)
            
            if dis[i][u] == d:
                for msk in path[u]:
                    w, v = divmod(msk, n)
                    
                    if dis[i][v] > dis[i][u] + w:
                        dis[i][v] = dis[i][u] + w
                        heappush(pq, f(dis[i][v], v))
        
    ts = []
    cs = []
    
    for _ in range(n):
        x, y = MII()
        ts.append(x)
        cs.append(y)
    
    ans = [inf] * n
    ans[s] = 0
    
    pq = [f(0, s)]
    
    while pq:
        d, u = divmod(heappop(pq), n)
        
        if ans[u] == d:
            for v in range(n):
                if dis[u][v] <= ts[u]:
                    nd = d + cs[u]
                    if nd < ans[v]:
                        ans[v] = nd
                        heappush(pq, f(nd, v))
    
    print(ans[t] if ans[t] < inf else -1)
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    s --, t --;

    vector<vector<pair<int, int>>> path(n);
    
    while (m --) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        path[u].emplace_back(v, w);
        path[v].emplace_back(u, w);
    }

    long long inf = 1e14;
    vector<vector<long long>> dis(n, vector<long long>(n, inf));

    for (int i = 0; i < n; i ++) {
        dis[i][i] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, i});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (dis[i][u] == d) {
                for (auto &[v, w]: path[u]) {
                    long long nd = d + w;
                    if (nd < dis[i][v]) {
                        dis[i][v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
        }
    }

    vector<int> ts(n), cs(n);
    for (int i = 0; i < n; i ++)
        cin >> ts[i] >> cs[i];

    vector<long long> ans(n, inf);
    ans[s] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (u == t) return cout << d, 0;

        if (ans[u] == d) {
            for (int v = 0; v < n; v ++) {
                if (dis[u][v] <= ts[u]) {
                    long long nd = d + cs[u];
                    if (nd < ans[v]) {
                        ans[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
        }
    }

    cout << -1;

    return 0;
}
```