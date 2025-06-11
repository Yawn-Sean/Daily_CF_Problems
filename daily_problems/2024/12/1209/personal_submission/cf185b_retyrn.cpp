int S, a, b, c;

void solve() {
    cin >> S >> a >> b >> c;
    int s = (a + b + c);
    if (s == 0) {
        cout << S << ' ' << 0 << ' ' << 0 << endl;
        return;
    }
    double x = 1.0 * a / s * S;
    double y = 1.0 * b / s * S;
    double z = 1.0 * c / s * S;
    cout << x << ' ' << y << ' ' << z << endl;
}