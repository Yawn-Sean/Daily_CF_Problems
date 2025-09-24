/*
如果有直线经过圆心，则显然是 0.5 0.5，这种直线只需要 c = 0 就好了
否则，我们应该找圆心到直线距离最短的那个直线
找到之后，如何算面积？
考虑用扇形减去三角形
*/

LL a[N], b[N], c[N], n, r;

void meibao() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if (c[i] == 0) {
            cout << "0.5 0.5\n";
            return;
        }
    }

    auto get_dist = [&] (LL a, LL b, LL c) -> double {
        return fabs((1.0 * c) / sqrt(a * a + b * b));
    };

    long double min_dist = r + 1;
    for (int i = 1; i <= n; i++) {
        long double dist = get_dist(a[i], b[i], c[i]);
        if (dist < min_dist) {
            min_dist = dist;
        }
    }

    long double angle = 2 * acos(min_dist / r);
    long double s1 = angle * r * r / 2;
    long double s2 = r * sin(angle / 2) * min_dist;
    long double min_s = s1 - s2, max_s = acos(-1) * r * r - min_s;
    // cout << min_s << " " << max_s << endl;
    min_s = min_s / (acos(-1) * r * r);
    max_s = 1 - min_s;
    cout << setprecision(15) << min_s << " " << max_s << "\n";
}   
