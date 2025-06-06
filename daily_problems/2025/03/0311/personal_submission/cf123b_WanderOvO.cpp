/*
把坏点在坐标系上画出来，发现是一系列直线
所有线上的格点都是坏点，要尽量少走
a, b >= 2
分别计算两个方向上中间有多少条线
考虑把同时为 1 和 -1 的坏点一次性跨过去，则答案为 max 两个方向要经过的坏点
*/

LL a, b, x1, y1, x2, y2;

void meibao() {
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    
    auto div = [&] (LL a, LL b) {
        LL res = a / b;
        if (b * res > a) {
            res--;
        }
        return res;
    };

    LL cnt1 = abs(div(x1 + y1, 2 * a) - div(x2 + y2, 2 * a));
    LL cnt2 = abs(div(x1 - y1, 2 * b) - div(x2 - y2, 2 * b));
    cout << max(cnt1, cnt2) << "\n";
}
