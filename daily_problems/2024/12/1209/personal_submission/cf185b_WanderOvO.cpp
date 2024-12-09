/*
拉格朗日乘数法
*/

void meibao() {
    int s, a, b, c;
    cin >> s >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) {
        cout << "0 0 0\n";
        return;
    }
    double x = (1.0 * a * s) / (a + b + c), y = (1.0 * b * s) / (a + b + c), z = (1.0 * c * s) / (a + b + c);
    cout << setprecision(15) << x << " " << y << " " << z << "\n";
}
