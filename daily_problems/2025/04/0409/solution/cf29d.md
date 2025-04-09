**提示 1：** 当你走到一个结点 $u$ 时，如何选择先走哪个子树呢？

一个简单的树遍历问题。

实际上我们只需考虑每个结点对于子结点的遍历顺序，这件事确定了整个图的遍历顺序也就确定了。

子结点的遍历顺序如何呢？为了目标的叶子节点序列中，越靠前的结点越先被遍历，我们可以计算每棵子树种最早被遍历的位置，而这个位置越靠前，越应该先遍历该子树。（不然遍历完别的子树再遍历该子树，该子树的叶子就排到后面去了）

于是可以用树 DP 确定子树中出现在序列里的最早位置，最后 DFS 过程中，将子树关于 DP 结果排序，按照排序结果为顺序遍历子结点即可。

最后，根据上述得到的 DFS 序列，再重新检查是否和题中叶子节点遍历顺序一致即可。

时间复杂度为 $\mathcal{O}(n\log n)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    path = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    is_leaf = [1] * n

    parent = [-1] * n
    que = [0]

    for u in que:
        for v in path[u]:
            if parent[u] != v:
                is_leaf[u] = 0
                parent[v] = u
                que.append(v)

    nodes = LGMI()
    k = len(nodes)

    vis = [n] * n
    for i in range(k):
        vis[nodes[i]] = i

    for i in range(n - 1, 0, -1):
        u = que[i]
        vis[parent[u]] = fmin(vis[parent[u]], vis[u])

    ans = []
    stk = [0]

    while stk:
        u = stk.pop()
        if u >= 0:
            if u > 0:
                ans.append(parent[u])
            stk.append(~u)
            path[u].sort(key=lambda x: -vis[x])
            for v in path[u]:
                if parent[v] == u:
                    stk.append(v)
        else:
            ans.append(~u)

    pt = 0
    for u in ans:
        if pt < k and nodes[pt] == u:
            pt += 1

    if pt == k: print(' '.join(str(x + 1) for x in ans))
    else: print(-1)
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    int k = 0;
    for (int i = 0; i < n; i ++) {
        if (i > 0 && path[i].size() == 1) {
            k ++;
        }
    }

    vector<int> nodes(k), vis(n, n);
    for (int i = 0; i < k; i ++) {
        cin >> nodes[i];
        nodes[i] --;
        vis[nodes[i]] = i;
    }

    auto dp = [&] (auto &self, int u, int p) -> void {
        for (auto &v: path[u]) {
            if (v != p) {
                self(self, v, u);
                vis[u] = min(vis[u], vis[v]);
            }
        }
    };

    dp(dp, 0, -1);

    vector<int> ans;

    auto dfs = [&] (auto &self, int u, int p) -> void {
        sort(path[u].begin(), path[u].end(), [&] (int i, int j) {return vis[i] < vis[j];});
        for (auto &v: path[u]) {
            if (v != p) {
                ans.emplace_back(u);
                self(self, v, u);
            }
        }
        ans.emplace_back(u);
    };

    dfs(dfs, 0, -1);

    int pt = 0;
    for (auto &x: ans) {
        if (pt < k && nodes[pt] == x) {
            pt ++;
        }
    }

    if (pt == k) for (auto &x: ans) cout << x + 1 << ' ';
    else cout << -1;

    return 0;
}
```