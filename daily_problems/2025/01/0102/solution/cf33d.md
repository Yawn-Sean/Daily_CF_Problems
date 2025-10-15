**提示 1：** 题目相当于几个不相交的圆，这样的圆们可以用一棵树表示。

**提示 2：** 考虑我们的目标，相当于查询树上的什么信息？

这题可能可以直接暴力通过（尤其是你使用 C++ 的话），但推荐学习以下方法来了解更多性质。

本题涉及到了平面几何中一个常见的树的转化。我们现在图中有若干个圆形两两不交，那么这些圆可以转化为一棵树。

怎么转化呢？我们将圆和包含它的最小的圆连一条边。容易说明，这个图中没有环，因为如果有环，考虑从环上最小的圆走到最大的圆的路径，这条路径是唯一的（每次只能走到恰好包含这个圆的圆），这与有环矛盾。

而如果将整个平面视作一个大圆，则整个图是连通的，因此构成一棵树。

而事实上，我们查询从一个点到另一个点经过几个圆，就相当于总树上的一个点走到另一个点，这件事实际上就是求树上路径的距离。

于是，我们可以使用两个点的深度和减去 LCA 深度的两倍来得到距离。

时间复杂度为 $\mathcal{O}(n(n+m)+q\log m)$ ，下面的实现实际上是 $\mathcal{O}((n+m)^2+q\log m)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, m, q = MII()

    rs = [2 * 10 ** 9]
    xs = [0]
    ys = [0]

    for _ in range(n):
        r = 0
        x, y = MII()
        rs.append(r)
        xs.append(x)
        ys.append(y)

    for _ in range(m):
        r, x, y = MII()
        rs.append(r)
        xs.append(x)
        ys.append(y)

    st_range = sorted(range(n + m + 1), key=lambda x: -rs[x])

    nth_parent = [[-1] * (n + m + 1) for _ in range(13)]
    depth = [0] * (n + m + 1)

    for i in range(1, n + m + 1):
        for j in range(i - 1, -1, -1):
            u, v = st_range[i], st_range[j]
            if (xs[u] - xs[v]) ** 2 + (ys[u] - ys[v]) ** 2 < (rs[u] - rs[v]) ** 2:
                nth_parent[0][u] = v
                depth[u] = depth[v] + 1
                break

    for i in range(1, 13):
        for j in range(n + m + 1):
            if nth_parent[i - 1][j] != -1:
                nth_parent[i][j] = nth_parent[i - 1][nth_parent[i - 1][j]]

    def lca(u, v):
        if depth[u] > depth[v]:
            u, v = v, u
        
        x = depth[v] - depth[u]
        while x:
            bit = (x & -x).bit_length() - 1
            v = nth_parent[bit][v]
            x -= x & -x
        
        if u == v:
            return u
        
        for i in range(12, -1, -1):
            if nth_parent[i][u] != nth_parent[i][v]:
                u = nth_parent[i][u]
                v = nth_parent[i][v]
        return nth_parent[0][u]

    outs = []
    for _ in range(q):
        u, v = MII()
        outs.append(depth[u] + depth[v] - 2 * depth[lca(u, v)] - 2 if u != v else 0)

    print('\n'.join(map(str, outs)))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> rs(n + m + 1), xs(n + m + 1), ys(n + m + 1);
    rs[0] = 2e9;
    xs[0] = 0;
    ys[0] = 0;

    for (int i = 1; i <= n; i ++) {
        rs[i] = 0;
        cin >> xs[i] >> ys[i];
    }

    for (int i = n + 1; i <= n + m; i ++)
        cin >> rs[i] >> xs[i] >> ys[i];
    
    vector<int> st_range(n + m + 1);
    iota(st_range.begin(), st_range.end(), 0);
    sort(st_range.begin(), st_range.end(), [&] (int i, int j) {return rs[i] > rs[j];});

    vector<vector<int>> nth_parent(13, vector<int>(n + m + 1));
    vector<int> depth(n + m + 1, 0);

    for (int i = 1; i <= n + m; i ++) {
        for (int j = i - 1; j >= 0; j --) {
            int u = st_range[i], v = st_range[j];
            if (1ll * (xs[u] - xs[v]) * (xs[u] - xs[v]) + 1ll * (ys[u] - ys[v]) * (ys[u] - ys[v]) < 1ll * (rs[u] - rs[v]) * (rs[u] - rs[v])) {
                nth_parent[0][u] = v;
                depth[u] = depth[v] + 1;
                break;
            }
        }
    }

    for (int i = 1; i < 13; i ++) {
        for (int j = 0; j <= n + m; j ++) {
            if (nth_parent[i - 1][j] != -1) {
                nth_parent[i][j] = nth_parent[i - 1][nth_parent[i - 1][j]];
            }
        }
    }

    auto lca = [&] (int u, int v) -> int {
        if (depth[u] > depth[v]) swap(u, v);

        int x = depth[v] - depth[u];

        while (x) {
            int bit = 31 - __builtin_clz(x & -x);
            v = nth_parent[bit][v];
            x -= x & -x;
        }

        if (u == v) return u;

        for (int i = 12; i >= 0; i --) {
            if (nth_parent[i][u] != nth_parent[i][v]) {
                u = nth_parent[i][u];
                v = nth_parent[i][v];
            }
        }
        return nth_parent[0][u];
    };

    while (q --) {
        int u, v;
        cin >> u >> v;
        cout << (u == v ? 0 : depth[u] + depth[v] - depth[lca(u, v)] * 2 - 2) << '\n';
    }

    return 0;
}
```
