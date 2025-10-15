**提示 1：** 无限金币有哪些情况呢？

**提示 2：** 循环 / 无中生有！

当 $a,b,c,d,e,f$ 都非 $0$ 的时候，我们只需看循环一圈物质是否变多了——一旦变多了就可以用多出来的物质转成黄金了！

$1$ 单位沙子可以变成 $\frac{b}{a}$ 单位铅， $\frac{b}{a}$ 单位铅可以变成 $\frac{bd}{ac}$ 单位黄金， $\frac{bd}{ac}$ 单位黄金可以变成 $\frac{bdf}{ace}$ 单位沙子。

如果有 $0$ 呢？

那就没办法绕圈了，只能 “无中生有”。如果 $c=0,d\gt 0$ 可以直接无中生黄金；如果 $a=0,b\gt 0,c\gt 0,d\gt 0$ 也可以无中生铅，再生黄金。

讨论上述情况即可。

时间复杂度为 $\mathcal{O}(1)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    a, b, c, d, e, f = MII()
    print("Ron" if a * c * e < b * d * f or (a == 0 and b and d) or (c == 0 and d) else "Hermione")
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << ((a * c * e < b * d * f || (!a && b && d) || (!c && d)) ? "Ron" : "Hermione");

    return 0;
}
```