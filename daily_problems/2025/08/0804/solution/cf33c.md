**提示 1：** 每个元素的权重可能如何？

这题非常的简单！

因为操作的是前缀和后缀，所以最后每个元素的权重一定是，开始一段 $-1$ ，中间一段 $1$ ，最后一段 $-1$ （每一段都可以是空的）。

于是我们用 $dp[status][idx]$ 作为 DP 的数组，表示在第 $status$ 段时，遍历到第 $idx$ 情况下的最大和。接下来只需看后面的元素给哪一段就可以进行状态转移了。

时间复杂度为 $\mathcal{O}(n)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    nums = LII()
    
    dp1, dp2, dp3 = 0, 0, 0
    for x in nums:
        dp3 = fmax(dp2, dp3) - x
        dp2 = fmax(dp1, dp2) + x
        dp1 -= x
    
    print(max(dp1, dp2, dp3))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int dp1 = 0, dp2 = 0, dp3 = 0;

    while (n --) {
        int x;
        cin >> x;
        
        dp3 = max(dp2, dp3) - x;
        dp2 = max(dp1, dp2) + x;
        dp1 -= x;
    }

    cout << max(dp2, dp3);

    return 0;
}
```