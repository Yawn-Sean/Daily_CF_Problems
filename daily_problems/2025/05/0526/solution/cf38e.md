**提示 1：** 如果我们知道固定了哪些之后，成本怎么算？

**提示 2：** 相当于两个固定的位置之间，中间部分球的总成本的和。

其实整体的成本肯定只跟你固定了哪些位置有关。

而每个球的滚动成本只跟其左侧第一个固定了的位置有关。

于是考虑从右到左进行 DP，假设最左侧固定位置为 $i$ 时，最小的成本为 $dp[i]$ 。那么 $dp[i]$ 怎么计算呢？

考虑 $i$ 右侧第一个设置障碍物的地方 $i'$ ，则 $i'$ 对应的成本是 $dp[i']$ ，接下来只需考虑 $i\sim i'$ 之间的球的移动成本就行。其成本实质上是这部分球的坐标和减去他们到达的坐标和。前半部分可以用前缀和的维护快速得到，因此是 $\mathcal{O}(1)$ 的（当然，如果你顺序遍历各个位置，也可以不使用前缀和）。

时间复杂度为 $\mathcal{O}(n^2)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    xs = []
    cs = []

    for _ in range(n):
        x, c = MII()
        xs.append(x)
        cs.append(c)

    order = sorted(range(n), key=lambda x: -xs[x])

    acc = [0] * (n + 1)
    for i in range(n):
        acc[i + 1] = acc[i] + xs[order[i]]

    inf = 10 ** 18
    dp = [inf] * (n + 1)

    dp[0] = 0

    for i in range(n):
        for j in range(i + 1):
            dp[i + 1] = fmin(dp[i + 1], dp[j] + cs[order[i]] + acc[i + 1] - acc[j] - xs[order[i]] * (i + 1 - j))

    print(dp[n])
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> xs(n), cs(n);
    for (int i = 0; i < n; i ++)
        cin >> xs[i] >> cs[i];
    
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return xs[i] > xs[j];});

    vector<long long> acc(n + 1, 0);
    for (int i = 0; i < n; i ++)
        acc[i + 1] = acc[i] + xs[order[i]];
    
    long long inf = 1e18;
    vector<long long> dp(n + 1, inf);
    dp[0] = 0;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= i; j ++) {
            dp[i + 1] = min(dp[i + 1], dp[j] + cs[order[i]] + acc[i + 1] - acc[j] - 1ll * xs[order[i]] * (i + 1 - j));
        }
    }

    cout << dp[n];

    return 0;
}
```