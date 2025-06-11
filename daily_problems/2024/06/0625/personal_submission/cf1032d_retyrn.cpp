double a, b, c;
double x1, y1, x2, y2;

double get(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
    cin >> a >> b >> c;
    cin >> x1 >> y1 >> x2 >> y2;
    double res = fabs(x1 - x2) + fabs(y1 - y2);
    
    res = min(res, get(x1, (-a * x1 - c) / b, x2, (-a * x2 - c) / b) + fabs(y1 - (-a * x1 - c) / b) + fabs(y2 - (-a * x2 - c) / b));
    res = min(res, get(x1, (-a * x1 - c) / b, (-b * y2 - c) / a, y2) + fabs(y1 - (-a * x1 - c) / b) + fabs(x2 - (-b * y2 - c) / a));
    res = min(res, get((-b * y1 - c) / a, y1, x2, (-a * x2 - c) / b) + fabs(x1 - (-b * y1 - c) / a) + fabs(y2 - (-a * x2 - c) / b));
    res = min(res, get((-b * y1 - c) / a, y1, (-b * y2 - c) / a, y2) + fabs(x1 - (-b * y1 - c) / a) + fabs(x2 - (-b * y2 - c) / a));
    cout << res << endl;
}