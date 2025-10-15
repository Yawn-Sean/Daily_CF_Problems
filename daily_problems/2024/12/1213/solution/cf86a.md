**提示 1：** 这个函数并没那么复杂，想想它到底算了什么？是什么基本函数？

**提示 2：** 上面的函数求最值，应该分类讨论什么？

本题要求将数位的每一位都用 $9$ 减，再用原数去乘。

那么，假设原数 $x$ 有 $k$ 位，那么第一步得到的数等于 $k$ 个 $9$ 组成的多位数再减去 $x$ ，即 $10^k-1-x$ 。

于是我们要最大化的目标是 $x\times (10^k-1-x)$ 。

容易发现 $10^i$ 的计算结果比任意 $i$ 位数的结果都大（相乘的两项，每项位数都更大），因此我们只需考虑区间内位数最大的部分。

上述目标实际上是二次函数。因此只需讨论能否取到最接近对称轴的数值。

上述函数的最值在 $\frac{1}{2}10^k$ 和 $\frac{1}{2}10^k-1$ 处取到。

如果这两个数都在 $r$ 右侧，直接取 $r$ ；如果两个数都在 $l$ 左侧，直接取 $l$ ；否则直接取上述两者 $\frac{1}{2}10^k$ 和 $\frac{1}{2}10^k-1$ 之一即可。

时间复杂度为 $\mathcal{O}(\log M)$ ，来源于求位数等。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    l, r = MII()
    v = 10 ** len(str(r)) - 1
    mid = v // 2
    
    if mid <= l: print(l * (v - l))
    elif mid >= r: print(r * (v - r))
    else: print(mid * (v - mid))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, r;
    cin >> l >> r;

    long long x = 1;
    while (x <= r)
        x *= 10;
    
    x -= 1;
    long long mid = x / 2;

    if (mid <= l) cout << 1ll * l * (x - l);
    else if (mid >= r) cout << 1ll * r * (x - r);
    else cout << mid * (x - mid);

    return 0;
}
```
