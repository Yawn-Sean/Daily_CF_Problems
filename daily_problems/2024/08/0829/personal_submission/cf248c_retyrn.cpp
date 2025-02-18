double y1, y2, yw, xb, yb, r;

inline double norm(double x, double y) {
    return sqrt(x * x + y * y);
}
void solve() {
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;
    double y = y1 + r;
    double x = (yw - y - r) / (yw - yb - r + yw - y - r) * xb;
    
    double d = x * (y2 - y) / norm(yw - y - r, x);
    if (d < r) {
        cout << -1 << endl;
        return;
    }
    cout << x << endl;
}