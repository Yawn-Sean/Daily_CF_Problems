**提示 1：** 先考虑每次检查时每个位置可能的钻石配置。

**提示 2：** 每次拿钻石至少要操作几次？

不妨设检查的时候第一个位置的钻石变动了 $dx$ 颗，则所有偶数的位置都变动了 $-dx$ 颗，奇数的位置都变动了 $dx$ 颗。

如果奇数的位置和偶数的位置数量相同，则总数不变，因此偷不出来。

否则，假设奇数的每个位置减少了 $dx$ ，则总数减少了 $dx$ 。

而每减少 $1$ ，则需要调整 $\frac{n+1}{2}$ 次（直接模拟即可构造，证明也很容易，因为每个位置至少都得操作 $1$ 次）。

所以每分钟能偷的钻石数量等于 $k$ 除以上述结果，再乘以 $m$ 分钟即可。

注意 $dx$ 不能超过奇数的位置的最小数值，所以再跟对应数值取最小值再输出即可。

时间复杂度为 $\mathcal{O}(n)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, m, k = MII()
    nums = LII()

    if n % 2 == 0: print(0)
    else: print(fmin(min(nums[::2]), m // (n // 2 + 1) * k))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    long long val = 1e9, x;

    for (int i = 0; i < n; i ++) {
        cin >> x;
        if (i % 2 == 0) val = min(val, x);
    }

    if (n % 2 == 0) cout << 0;
    else cout << min(val, 1ll * m / (n / 2 + 1) * k);

    return 0;
}
```