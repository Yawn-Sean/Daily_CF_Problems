/*
横坐标之差越大，纵坐标之差越大，并且大的可行的话小的一定可行，具有单调性
不妨二分横坐标之差最大到底是多少，然后检查是否可行
假设横坐标之差是 d1，则纵坐标之差就是 d1 * b / a = d2
左下角的坐标是 (x0, y0)，则应该满足 x0 <= x <= x0 + d1，y0 <= y <= y0 + d2
x0 + d1 <= n，y0 + d2 <= m
解得 max(x - d1, 0) <= x0 <= min(x, n - d1), max(y - d2, 0) <= y0 <= min(y, m - d2)
只要这个范围不是空集，就说明可行（如果所有情况都无解怎么办？）
至此，可以求解出横坐标之差的最大值，也就知道了纵坐标最大差
接下来，最小化中心和 (x, y) 的欧氏距离
不妨设要最小化的距离函数是欧式距离的平方的 4 倍，这样一定是整数
中心坐标：((2 * x1 + d1) / 2, (2 * y1 + d2) / 2)
距离函数 f = (2 * x - 2 * x1 - d1)^2 + (2 * y - 2 * y1 - d2)^2
这两项是独立的可以看成关于 2 * x1 的二次函数以及关于 2 * y1 的二次函数，分别求最小值
对称轴是 2 * x1 = (2 * x - d1) 和 2 * y1 = (2 * y - d2)
但是定义域中可能不包含对称轴，所以要讨论一下
*/

LL n, m, x, y, a, b;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void meibao() {
    cin >> n >> m >> x >> y >> a >> b;
    LL g = gcd(a, b);
    a /= g;
    b /= g;
    LL l = 1, r = n / a, mid;

    auto check = [&] (LL ans) -> bool {
        LL d1 = ans * a;
        LL d2 = d1 / a * b;
        LL low_x = max(x - d1, 0LL), hi_x = min(x, n - d1);
        LL low_y = max(y - d2, 0LL), hi_y = min(y, m - d2);
        return (low_x <= hi_x && low_y <= hi_y);
    };
    
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    LL d1 = 0;
    if (check(r)) {
        d1 = r;
    } else if (check(l)) {
        d1 = l;
    }
    d1 *= a;
    LL d2 = d1 / a * b;
    LL low_x = max(x - d1, 0LL), hi_x = min(x, n - d1);
    LL low_y = max(y - d2, 0LL), hi_y = min(y, m - d2);
    LL x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0;
    if (2 * x - d1 < 2 * low_x) {
        x_1 = low_x;
    } else if (2 * x - d1 > 2 * hi_x) {
        x_1 = hi_x;
    } else {
        if ((2 * x - d1) / 2 >= low_x) {
            x_1 = (2 * x - d1) / 2;
        } else {
            x_1 = (2 * x - d1 + 1) / 2;
        }
    }

    if (2 * y - d2 < 2 * low_y) {
        y_1 = low_y;
    } else if (2 * y - d2 > 2 * hi_y) {
        y_1 = hi_y;
    } else {
        if ((2 * y - d2) / 2 >= low_y) {
            y_1 = (2 * y - d2) / 2;
        } else {
            y_1 = (2 * y - d2 + 1) / 2;
        }
    }

    x_2 = x_1 + d1;
    y_2 = y_1 + d2;
    cout << x_1 << " " << y_1 << " " << x_2 << " " << y_2 << "\n";
}
