int aa, bb;
double a, b;

void meibao() {
    cin >> aa >> bb;
    a = aa;
    b = bb;
    double tot = 2 * a * b;
    if (a == 0 && b == 0) {
        cout << "1\n";
        return;
    } else if (a == 0) {
        cout << "0.5\n";
        return;
    } else if (b == 0) {
        cout << "1\n";
        return;
    }
    if (a < 4 * b) {
        cout << setprecision(20) << (a * a / 8 + a * b) / tot << "\n";
    } else {
        cout << setprecision(20) << ((2 * a - 4 * b) * b / 2 + a * b) / tot << "\n";
    }
}
