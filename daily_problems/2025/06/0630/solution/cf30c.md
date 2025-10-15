**提示 1：** 按照时间考虑每个目标。

**提示 2：** 状态是什么？什么情况下可以状态转移？

首先，一定按照时间的顺序射击每个目标。因此先关于时间排序。

假设我们最后射击目标为 $i$ 时的最优期望为 $dp[i]$ ，则状态转移就只需考虑下次设计什么。

假设下次射击的目标是 $j$ ，那么怎么判断能不能走到呢？就只需距离不超过 $t$ 。注意这里两边平方就可以只涉及整数运算了，虽然这里给的题目并卡不了用浮点数。

如果能转移，就可以用 $dp[i]+prob[j]$ 来更新 $dp[j]$ 了。对于每个 $i$ 尝试转移到所有时间更靠后的 $j$ 即可。

时间复杂度为 $\mathcal{O}(n^2)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    xs = []
    ys = []
    ts = []
    ps = []

    for _ in range(n):
        x, y, t, p = LI()
        x = int(x)
        y = int(y)
        t = int(t)
        p = float(p)
        xs.append(x)
        ys.append(y)
        ts.append(t)
        ps.append(p)

    st_range = sorted(range(n), key=lambda x: ts[x])
    dp = [0] * n

    for i in range(n):
        i1 = st_range[i]
        
        x1 = xs[i1]
        y1 = ys[i1]
        t1 = ts[i1]
        p1 = ps[i1]
        
        for j in range(i):
            i2 = st_range[j]
            
            x2 = xs[i2]
            y2 = ys[i2]
            t2 = ts[i2]
            p2 = ps[i2]
            
            if (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (t2 - t1) * (t2 - t1):
                dp[i1] = fmax(dp[i1], dp[i2])
        
        dp[i1] += p1

    print(max(dp))
```

C++ 做法如下——

```cpp []
struct node {
    int x, y, t;
    long double p;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<node> nodes(n);
    for (auto &v: nodes)
        cin >> v.x >> v.y >> v.t >> v.p;
    
    sort(nodes.begin(), nodes.end(), [&] (node x, node y) {
        return x.t < y.t;
    });

    vector<long double> dp(n, 0);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            if ((nodes[i].x - nodes[j].x) * (nodes[i].x - nodes[j].x) +
                (nodes[i].y - nodes[j].y) * (nodes[i].y - nodes[j].y) <=
                1ll * (nodes[i].t - nodes[j].t) * (nodes[i].t - nodes[j].t))
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += nodes[i].p;
    }

    cout << fixed << setprecision(15) << *max_element(dp.begin(), dp.end());

    return 0;
}
```
