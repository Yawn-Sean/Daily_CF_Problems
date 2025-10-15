**提示 1：** 这里是允许 $\mathcal{O}(n^2)$ 或稍大的复杂度通过的。

**提示 2：** 可以按照优先级顺序进行模拟，则往上模拟的时候就无需再多考虑优先级的问题了。

先看提示 2，我们将所有结点的士兵按照优先级升序排序，依次考虑他们。这样，就只需模拟这个士兵到达某个结点后，这个结点往父节点的边最早清空的时间。

为此，我们维护每个节点 $t$ 时刻被多少士兵使用，即可快速判断当前时刻是否是满的。

如何模拟上述过程呢？事实上你只需要暴力模拟复杂度就已经是对的了，因为每个结点到根节点的时间是不超过 $n-1$ 的（可以归纳法证明）。

因此，从某个节点 $u$ 出发，不断增加时间 $t$ 直到父边有空闲，再往父节点走，如此直至走到根节点。这里 $t$ 的自增次数不会超过 $n-1$ ，结点移动次数也不超过 $n-1$ ，因此总复杂度已经符合要求。

时间复杂度为 $\mathcal{O}(n^2)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    nums = LII()

    us = []
    vs = []
    cs = []

    path = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v, c = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        cs.append(c)
        path[u].append(i)
        path[v].append(i)

    cnt = [[0] * (n + 1) for _ in range(n)]

    parent = [-1] * n
    parent_cnt = [0] * n

    stk = [0]
    while stk:
        u = stk.pop()
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            c = cs[eid]
            if parent[u] != v:
                parent[v] = u
                parent_cnt[v] = c
                stk.append(v)

    ans = [-1] * n

    for i in sorted(range(n), key=lambda x: nums[x]):
        t = 0
        u = i

        while u:
            while cnt[u][t] == parent_cnt[u]:
                t += 1
            cnt[u][t] += 1
            t += 1
            u = parent[u]

        ans[i] = t

    print(' '.join(map(str, ans)))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums)
        cin >> x;

    vector<vector<pair<int, int>>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v, c;
        cin >> u >> v >> c;
        u --, v --;
        path[u].emplace_back(v, c);
        path[v].emplace_back(u, c);
    }

    vector<pair<int, int>> parent(n);

    auto dfs = [&] (auto &self, int u, int p) -> void {
        for (auto &[v, c]: path[u]) {
            if (v != p) {
                parent[v] = {u, c};
                self(self, v, u);
            }
        }
    };

    dfs(dfs, 0, -1);

    vector<vector<int>> cnt(n, vector<int>(n + 1, 0));

    vector<int> order(n), ans(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {return nums[i] < nums[j];});

    for (auto &i: order) {
        int u = i, t = 0;
        while (u) {
            auto [p, c] = parent[u];
            while (cnt[u][t] == c) t ++;
            cnt[u][t] ++, u = p, t ++;
        }
        ans[i] = t;
    }

    for (auto &x: ans) cout << x << ' ';

    return 0;
}
```