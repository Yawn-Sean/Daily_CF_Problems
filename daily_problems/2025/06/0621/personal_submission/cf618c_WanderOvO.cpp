/*
假设 a, b, c 三个点组成三角形
如果有 d 在三角形 abc 中，则 d 离 a 的距离一定 < max(b 离 a 的距离, c 离 a 的距离)
这样来看的话，找两个离自己最近的点，至少保证了不会有点在三角形内了，但是三角形可能退化成线段
由于输入保证了所有的点不都在同一条直线上，所以一定有解
改成枚举 a，先找一个最近的 b，然后再找一个不在 ab 直线上的最近的 c
可否钦定必选 1 号点？这样还有解吗？
首先 1 号点肯定有一个最近的其他点 b，另外肯定还有至少一个不在 1b 直线上的 c，这样肯定就存在最小的，所以有解
b 可以枚举确定，c 可以在 b 确定之后进行枚举
*/

LL x[N], y[N], n;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    int b = -1;
    LL mn = INFLL;

    auto get_dist = [&] (int i) -> LL {
        return (x[1] - x[i]) * (x[1] - x[i]) + (y[1] - y[i]) * (y[1] - y[i]);
    };

    for (int i = 2; i <= n; i++) {
        LL d = get_dist(i);
        if (d < mn) {
            mn = d;
            b = i;
        }
    }

    auto on_line = [&] (int i) -> LL {
        PLL v1 = {x[b] - x[1], y[b] - y[1]};
        PLL v2 = {x[i] - x[1], y[i] - y[1]};
        return v1.x * v2.y == v1.y * v2.x;
    };

    int c = -1;
    LL mn2 = INFLL;
    for (int i = 2; i <= n; i++) {
        if (i != b && !on_line(i)) {
            LL d = get_dist(i);
            if (d < mn2) {
                mn2 = d;
                c = i;
            }
        }
    }

    cout << "1 " << b << " " << c << "\n";
}
