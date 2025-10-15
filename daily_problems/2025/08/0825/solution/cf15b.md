**提示 1：** 需要计算的面积是什么？

**提示 2：** 可以先调整 $x_1,x_2,y_1,y_2$ 方便处理。

考虑最后要计算的面积。就是整个区域减去要扫过的地方。

而扫过的地方往左 / 右 / 上 / 下的最大距离可以预处理，根据这个数据可以得到两个矩形区域，我们要求的就是这两个矩形区域的并集。

所以只需用两个面积相加，再减去重叠部分的面积即可。

为了方便处理可以让 $x_1,x_2$ 有序， $y_1,y_2$ 有序，因为整体移动的距离是保持不变的，所以开始的矩形面积不变，重合部分也不变。

时间复杂度为 $\mathcal{O}(1)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, x1, y1, x2, y2 = MII()
        
        if x1 > x2: x1, x2 = x2, x1
        if y1 > y2: y1, y2 = y2, y1
        
        a = x1 + n - x2
        b = y1 + m - y2
        outs.append(n * m - 2 * a * b + fmax(0, a * 2 - n) * fmax(0, b * 2 - m))
    
    print('\n'.join(map(str, outs)))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        int a = x1 + n - x2, b = y1 + m - y2;
        cout << 1ll * n * m - 2ll * a * b + 1ll * max(0, 2 * a - n) * max(0, 2 * b - m) << '\n';
    }

    return 0;
}
```