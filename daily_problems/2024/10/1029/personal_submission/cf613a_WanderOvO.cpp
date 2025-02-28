struct Point {
    double x, y;
};

int n;
Point center;
Point ps[N];

double get_square_dist(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

void meibao() {
    cin >> n >> center.x >> center.y;
    for (int i = 1; i <= n; i++) {
        cin >> ps[i].x >> ps[i].y;
    }
    double mx = 0, mn = 1e25;
    for (int i = 1; i <= n; i++) {
        double d = get_square_dist(center, ps[i]);
        mx = max(mx, d);
        mn = min(mn, d);
    }
    for (int i = 1; i <= n; i++) {
        int j = i + 1;
        if (j > n) {
            j = 1;
        }
        double oa = get_square_dist(center, ps[i]);
        double ob = get_square_dist(center, ps[j]);
        double ab = get_square_dist(ps[i], ps[j]);
        double c = ((center.x - ps[i].x) * (ps[j].x - ps[i].x) + (center.y - ps[i].y) * (ps[j].y - ps[i].y)) / sqrt(ab);
        if (c < 0) {
            mn = min(mn, oa);
        } else if (c > sqrt(ab)) {
            mn = min(mn, ob);
        } else {
            mn = min(mn, oa - c * c);
        }
    }
    cout << setprecision(15) << acos(-1) * (mx - mn) << "\n";
}
