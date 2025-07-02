/*
任意三点不共线
最早相撞的是谁？
- 点 2-n 第一轮发送的飞船在互相到达时撞
- 点 2-n 第二轮发送的飞船在 1 号点撞了
- 1 号点第二轮发送的飞船和 2-n 号点第二轮发送的飞船撞了
对于第 1 种情况，只要两两计算是否会碰撞以及碰撞时间即可
由于任意 3 点不共线，组成了三角形，两边之和严格大于第 3 边，所以第 2 3 种情况肯定比第 1 种情况晚
*/
 
int n;
double x[N], y[N], z[N];
 
void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
 
    auto dist = [&] (int i, int j) -> double {
        return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]));
    };
 
    double res = 1e9;
    for (int i = 2; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double d1 = dist(1, i), d2 = dist(1, j), d3 = dist(i, j);
            if (d1 > d2) {
                swap(d1, d2);
            }
            double d = d2 - d1;
            res = min(res, d1 + d + (d3 - d) / 2);
        }
    }
    cout << setprecision(15) << res << "\n";
}
