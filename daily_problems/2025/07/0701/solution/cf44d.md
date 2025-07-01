**提示 1：** 其实求的东西很容易。

经过的点一定至少有三个。否则的话没办法相遇。

所以考虑经过的点是 $1,i,j$ ，则总路程确定，除以总速度即时间。

事实上，这个三角形画出来，你可以找到双方的运动轨迹，也就是上述最小值是可以取到的。因此枚举即可。

时间复杂度为 $\mathcal{O}(n^2)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    xs = []
    ys = []
    zs = []

    for _ in range(n):
        x, y, z = MII()
        xs.append(x)
        ys.append(y)
        zs.append(z)

    ans = inf

    def dis(i, j):
        return math.hypot(xs[i] - xs[j], ys[i] - ys[j], zs[i] - zs[j])

    for i in range(1, n):
        for j in range(i + 1, n):
            ans = fmin(ans, dis(0, i) + dis(0, j) + dis(i, j))

    print(ans / 2)
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> xs(n), ys(n), zs(n);
    for (int i = 0; i < n; i ++)
        cin >> xs[i] >> ys[i] >> zs[i];
    
    long double ans = 1e8;

    auto dis = [&] (int i, int j) -> long double {
        return powl((xs[i] - xs[j]) * (xs[i] - xs[j]) + 
                    (ys[i] - ys[j]) * (ys[i] - ys[j]) + 
                    (zs[i] - zs[j]) * (zs[i] - zs[j]), 0.5);
    };

    for (int i = 1; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            ans = min(ans, dis(0, i) + dis(0, j) + dis(i, j));
        }
    }

    cout << fixed << setprecision(15) << ans / 2;

    return 0;
}
```