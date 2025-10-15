int a, b;

void solve() {
    cin >> a >> b;
    // p - 4q >= 0 a != 0
    
    if (b == 0) {
        cout << 1 << endl;
        return;
    }
    if (a == 0) {
        cout << 0.5 << endl;
        return;
    }
    
    if (b * 4 >= a) {
        double res = 0.5 + (double)a / b / 16;
        cout << res << endl;
    }
    else {
        double res = 1.0 - (double)b / a;
        cout << res << endl;
    }
    
}