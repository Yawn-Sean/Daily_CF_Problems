**提示 1：** 最关键的点在速度：追赶者速度不小于被追赶者。

**提示 2：** 想想速度差别意味着什么：一旦被追到后续无法逃脱。

由于追赶者的速度不小于被追赶者，因此，一旦某个点被追到了，则后续追赶者可以沿着被追赶者的路线继续走，因此总能在被追赶者之前到达后续的每一个点，总能追赶上。

于是，后续的任何一个点都可以成为相遇的位置。而我们要找到第一个相遇的位置。

因此这里有二段性，考虑二分。

我们先枚举折线的每一段，如果能追赶上，一定存在某一段的结尾可以被追赶上，我们在第一个结尾能追上的段进行二分即可。

二分时，只需计算二分位置的直线距离进而得到总用时。计算相对容易，只需使用三维空间的距离 $\sqrt{(x_1-x_2)^2+(y_1-y_2)^2+(z_1-z_2)^2}$ 。计算过程中可以保留前面所有段的折线行走的总用时。

如果每一段的结尾都无法追赶上，则输出 `'NO'` 。

时间复杂度为 $\mathcal{O}(n+\log\epsilon^{-1})$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    xs = [0] * (n + 1)
    ys = [0] * (n + 1)
    zs = [0] * (n + 1)

    for i in range(n + 1):
        xs[i], ys[i], zs[i] = MII()

    vp, vs = MII()
    px, py, pz = MII()

    def dis(x1, y1, z1, x2, y2, z2):
        return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) ** 0.5

    cur_time = 0
    for i in range(n):
        new_time = dis(xs[i], ys[i], zs[i], xs[i + 1], ys[i + 1], zs[i + 1]) / vs
        time = dis(px, py, pz, xs[i + 1], ys[i + 1], zs[i + 1]) / vp
        if time <= cur_time + new_time:
            l, r = 0, 1
            for _ in range(50):
                m = (l + r) / 2
                nx, ny, nz = xs[i] + m * (xs[i + 1] - xs[i]), ys[i] + m * (ys[i + 1] - ys[i]), zs[i] + m * (zs[i + 1] - zs[i])
                if dis(px, py, pz, nx, ny, nz) / vp <= cur_time + dis(xs[i], ys[i], zs[i], nx, ny, nz) / vs:
                    r = m
                else:
                    l = m
            nx, ny, nz = xs[i] + m * (xs[i + 1] - xs[i]), ys[i] + m * (ys[i + 1] - ys[i]), zs[i] + m * (zs[i + 1] - zs[i])
            print('YES')
            print(dis(px, py, pz, nx, ny, nz) / vp)
            print(nx, ny, nz)
            exit()
        cur_time += new_time

    print('NO')
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> xs(n + 1), ys(n + 1), zs(n + 1);
    for (int i = 0; i <= n; i ++)
        cin >> xs[i] >> ys[i] >> zs[i];

    int vp, vs, px, py, pz;
    cin >> vp >> vs >> px >> py >> pz;

    auto dis = [&] (long double x1, long double y1, long double z1, long double x2, long double y2, long double z2) -> long double {
        return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
    };

    cout << fixed << setprecision(20);
    long double cur_time = 0;
    for (int i = 0; i < n; i ++) {
        long double new_time = dis(xs[i], ys[i], zs[i], xs[i + 1], ys[i + 1], zs[i + 1]) / vs;
        long double time = dis(px, py, pz, xs[i + 1], ys[i + 1], zs[i + 1]) / vp;
        if (time <= cur_time + new_time) {
            long double l = 0, r = 1, m, nx, ny, nz;
            for (int j = 0; j < 50; j ++) {
                m = (l + r) / 2;
                nx = xs[i] + m * (xs[i + 1] - xs[i]);
                ny = ys[i] + m * (ys[i + 1] - ys[i]);
                nz = zs[i] + m * (zs[i + 1] - zs[i]);
                if (dis(px, py, pz, nx, ny, nz) / vp <= cur_time + dis(xs[i], ys[i], zs[i], nx, ny, nz) / vs) r = m;
                else l = m;
            }
            cout << "YES\n";
            cout << dis(px, py, pz, nx, ny, nz) / vp << '\n';
            cout << nx << ' ' << ny << ' ' << nz;
            return 0;
        }
        cur_time += new_time;
    }
    cout << "NO";

    return 0;
}
```


