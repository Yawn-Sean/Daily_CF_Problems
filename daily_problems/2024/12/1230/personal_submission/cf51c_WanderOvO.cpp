int n;
double x[N];

bool check(double d) {
    double x1 = x[1] + d;
    int idx = 1;
    for ( ; idx <= n && x[idx] < x1 + d; idx++);
    if (idx > n) return true;
    double x2 = x[idx] + d;
    for ( ; idx <= n && x[idx] < x2 + d; idx++);
    if (idx > n) return true;
    double x3 = x[idx] + d;
    for ( ; idx <= n && x[idx] < x3 + d; idx++);
    return idx > n;
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);
    double l = 0, r = x[n], mid;
    for (int i = 1; i <= 100; i++) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.6lf\n", l);
    double x1 = x[1] + l;
    printf("%.6lf ", x1);
    int idx = 1;
    for ( ; idx <= n && (x[idx] < x1 + l || fabs(x[idx] - x1 - l) < eps); idx++);
    if (idx > n) {
        printf("%.6lf %.6lf\n", x1, x1);
        return;
    }

    double x2 = x[idx] + l;
    printf("%.6lf ", x2);
    for ( ; idx <= n && (x[idx] < x2 + l || fabs(x[idx] - x2 - l) < eps); idx++);
    if (idx > n) {
        printf("%.6lf\n", x2);
        return;
    }
    double x3 = x[idx] + l;
    printf("%.6lf\n", x3);
}
