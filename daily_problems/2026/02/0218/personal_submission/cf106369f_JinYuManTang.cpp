template<class T>
bool chmin(T &a, T b) {
    if (a <= b) return false;
    a = b;
    return true;
}

void solve() {
    long double b1, b2, h;
    cin >> b1 >> b2 >> h;

    auto cal = [&](long double x) -> long double {
        long double s1 = b1 * x / 2, s2 = b2 * (h - x) / 2;
        long double s3 = ((b1 + b2) * h / 2 - s1 - s2) / 2;
        vector<long double> area = {s1, s2, s3};
        sort(area.begin(), area.end());
        return area.back() - area[0];
    };

    vector<long double> xs;
    long double eps = 1e-12;
    if (fabs(3.0L * b1 - b2) > 0) {
        long double x1 = b1 * h / (3.0L * b1 - b2);
        if (0 < x1 && x1 < h) {
            xs.push_back(x1);
        }
    }
    long double x2 = b2 * h / (b1 + b2);
    xs.push_back(x2);
    if (fabs(3.0L * b2 - b1) > 0) {
        long double x3 = (2.0L * b2 * h - b1 * h) / (3.0L * b2 - b1);
        if (0 < x3 && x3 < h) {
            xs.push_back(x3);
        }
    }
    long double res = 1e18;
    for (long double x: xs) {
        chmin(res, cal(x));
    }

    cout << fixed << setprecision(20) << res;
}
