/*
两个圆相离：(d - r1 - r2) / 2
两个圆外切：0
两个圆相交：0
两个圆内切：0
一个圆包含另一个圆：圆上两个点的最小距离 / 2, min(r[1] - r[2] - d, 2 * r[1] - 2 * r2 - (r[1] - r[2] - d))
*/

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void meibao() {
    double x[3], y[3], r[3];
    for (int i = 1; i <= 2; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    if (r[1] < r[2]) {
        swap(r[1], r[2]);
        swap(x[1], x[2]);
        swap(y[1], y[2]);
    }

    double d = dist(x[1], y[1], x[2], y[2]);
    if (r[1] + r[2] < d) {
        cout << setprecision(15) << (d - r[1] - r[2]) / 2 << "\n";
    } else if (d > r[1] - r[2]) {
        cout << "0\n";
    } else {
        cout << setprecision(15) << (min(r[1] - r[2] - d, 2 * r[1] - 2 * r[2] - (r[1] - r[2] - d))) / 2 << "\n";
    }
}
