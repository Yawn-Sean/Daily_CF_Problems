**提示 1：** 这题博弈的目标是什么呢？

**提示 2：** 有什么不同的状态？如何控制状态数量？

这题要求 $b$ 个物品放入 $a$ 个地方的方案数，每个物品都能挑位置，所以根据乘法原理，结果是 $a^b$ ，这个数只能小于 $n$ 。

如果 $a\geq 2,b\geq 2$ ，那么 $a\leq\sqrt{n}, b\leq\log n$ ，所以对应的总状态数量不超过 $\mathcal{O}(\sqrt{n}\log n)$ 的量级。这种情况的边界就在于 $a^b\geq n$ 的情况下。此时执行前一步的人必负，所以可以认为到达的这个状态是必胜的。

接下来就处理 $a=1$ 或者 $b=1$ 的情况就行。

$a=1$ 时，如果选择对 $a$ 加 $1$ ，那么一旦 $b\geq\log n$ ，那么就已经输了；因此总是选择对 $b$ 操作，此时一定是平局。所以实际上只需考虑 $b\lt\log n$ 的情况，这一部分数量也很有限。

而 $b=1$ 时，如果 $a^2\geq n$ ，那么实际上也无法对 $b$ 操作，只能不断增加 $a$ 。这种情况下的胜负关系只由 $n-a$ 的数值决定。而对于 $a^2\lt n$ ，状态总数量也就不超过 $\sqrt{n}$ 了。

综上，通过分类讨论，把两段特殊情况的状态数量也压缩了，同时，我们也得到了边界情况下的胜负关系。

而这些状态怎么转移呢？在一个状态是必胜 / 必负的情况下，如果一个状态可以走向一个必负状态，那它就是必胜的；否则该状态是必负的。根据这个逻辑，从 $a,b$ 更大的地方考虑到 $a,b$ 更小的地方进行状态转移就行。

一般而言，涉及平局的博弈 DP 还需要考虑在无法必胜的情况下，能否让对方的最优选择只是平局，在这种情况下，DP 转移结果是平局。

但本题无需讨论这种情况，因为唯一一个可以到达平局的状态是 $1,\lfloor\log n\rfloor$ ，其能到达的 $2,\lfloor\log n\rfloor$ 是无法进行操作的（因为操作 $a,b$ 中的任何一个都会超过 $n$ ），因而必胜。

时间复杂度为 $\mathcal{O}(\sqrt{n}\log n)$ 。但是这题输出真逆天吧！

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    a, b, n = MII()

    dp = [[-1] * (10 ** 5) for _ in range(32)]

    for i in range(1, 32):
        for j in range(1, 10 ** 5):
            if dp[i][j - 1] == 0 or j ** i >= n: dp[i][j] = 0

    if dp[1][-1] == -1: dp[1][-1] = (n - a) & 1

    for i in range(1, 32):
        if dp[i - 1][1] == 2 or 1 << i >= n:
            dp[i][1] = 2

    for i in range(30, 0, -1):
        for j in range(10 ** 5 - 2, 0, -1):
            if dp[i][j] == -1:
                if dp[i + 1][j] == 1 or dp[i][j + 1] == 1:
                    dp[i][j] = 0
                else:
                    dp[i][j] = 1

    ans = ["Masha", "Stas", "Missing"]

    print(ans[dp[b][a]])
```

C++ 做法如下——

```cpp []
long long p(int i, int j) {
    long long res = 1;
    for (int k = 0; k < j; k ++)
        res *= i;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    vector<vector<int>> dp(32, vector<int>(100000, -1));

    for (int i = 1; i < 32; i ++) {
        for (int j = 1; j < 100000; j ++) {
            if (dp[i][j - 1] == 0 || p(j, i) >= n) dp[i][j] = 0;
        }
    }

    if (dp[1].back() == -1) dp[1].back() = (n - a) & 1;

    for (int i = 1; i < 32; i ++) {
        if (dp[i - 1][1] == 2 || (1 << i) >= n) {
            dp[i][1] = 2;
        }
    }

    for (int i = 30; i > 0; i --) {
        for (int j = 100000 - 2; j > 0; j --) {
            if (dp[i][j] == -1) {
                if (dp[i + 1][j] == 1 || dp[i][j + 1] == 1)
                    dp[i][j] = 0;
                else dp[i][j] = 1;
            }
        }
    }

    vector<string> ans = {"Masha", "Stas", "Missing"};
    cout << ans[dp[b][a]];

    return 0;
}
```