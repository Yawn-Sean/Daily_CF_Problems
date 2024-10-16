vector<Point> ps;
int n;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        ps.pb({x, y});
    }
    polarSort(ps);
    double res = 0;
    for (int i = 1; i < n; i++) {
        res = max(res, atan2(ps[i].y, ps[i].x) - atan2(ps[i - 1].y, ps[i - 1].x));
    }
    cout << setprecision(15) << min(2 * acos(-1) - res, atan2(ps[n - 1].y, ps[n - 1].x) - atan2(ps[0].y, ps[0].x)) * 180 / acos(-1) << "\n";
}  
