**提示 1：** 考虑枚举 $\max g_i$ 。

**提示 2：** 实际上，重要的边改变的并不多。

两个都是 $\max$ ，所以常见的想法是枚举其中的一个 $\max$ 。

不妨枚举 $\max g_i$ ，此时我们相当于对于一系列 $g_i\leq M$ 的边，尝试找到其中 $s_i$ 最小的若干条边，使得整个图连通。

如果考虑所有的边，那么实际上还是 $m^2\log m$ 的，很不符合要求。

但其实，这些边中很多是并不重要的。只有最小生成森林中的边之后可能被用到，因此存下来这些边。

在增大 $\max g_i$ 的过程中，每次新增一条边，把这条边根据 $s_i$ 的大小插入到原有的边序列中，再顺序遍历一遍就可以求出此时的最小生成森林，也就得到了新的边集。

如果完全连通，我们就得到了此时最小的 $\max s_i$ ，再用题中的式子即可。

时间复杂度为 $\mathcal{O}(mn\alpha(n))$ ，因为我们需要枚举 $m$ 次 $\max g_i$ ，同时每次枚举实际考虑的是最小生成森林里面的 $\mathcal{O}(n)$ 条边，并在插入排序一条边后，再跑一边最小生成森林。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, m = MII()
    g, s = MII()
    
    us = []
    vs = []
    gs = []
    ss = []
    
    for _ in range(m):
        u, v, x, y = MII()
        u -= 1
        v -= 1
        
        us.append(u)
        vs.append(v)
        gs.append(x)
        ss.append(y)
    
    inf = 10 ** 18 * 3
    ans = inf
    
    used = [0] * m
    
    st_range_g = sorted(range(m), key=lambda x: gs[x])
    uf = UnionFind(n)
    
    cur = []
    
    for i in st_range_g:
        cur.append(i)
        
        for j in range(len(cur) - 1, 0, -1):
            if ss[cur[j]] < ss[cur[j - 1]]:
                cur[j], cur[j - 1] = cur[j - 1], cur[j]
        
        ncur = []
        
        uf.init()
        
        cnt = n
        cs = 0
        
        for eid in cur:
            if uf.merge(us[eid], vs[eid]):
                cnt -= 1
                cs = ss[eid]
                ncur.append(eid)
        
        if cnt == 1:
            ans = fmin(ans, gs[i] * g + cs * s)
        
        cur = ncur
    
    print(ans if ans < inf else -1)
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, g, s;
    cin >> n >> m >> g >> s;

    vector<array<int, 4>> edges(m);

    for (auto &x: edges) {
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        x[0] --, x[1] --;
    }

    sort(edges.begin(), edges.end(), [&] (array<int, 4> x, array<int, 4> y) {return x[2] < y[2];});

    atcoder::dsu uf(n);

    vector<int> cur_edges;
    long long inf = 3e18, ans = inf;

    for (int i = 0; i < m; i ++) {
        cur_edges.emplace_back(i);

        for (int j = cur_edges.size() - 1; j > 0; j --) {
            if (edges[cur_edges[j]][3] < edges[cur_edges[j - 1]][3]) {
                swap(cur_edges[j], cur_edges[j - 1]);
            }
        }

        uf.init();

        vector<int> new_edges;
        int cs = 0, cnt = n;

        for (auto &eid: cur_edges) {
            if (uf.merge(edges[eid][0], edges[eid][1])) {
                cs = edges[eid][3], cnt --, new_edges.emplace_back(eid);
            }
        }

        if (cnt == 1) ans = min(ans, 1ll * edges[i][2] * g + 1ll * cs * s);
        cur_edges.swap(new_edges);
    }

    cout << (ans < inf ? ans : -1);

    return 0;
}
```