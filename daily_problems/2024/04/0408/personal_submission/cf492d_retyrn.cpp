int q, x, y, n;

void solve() {
    cin >> q >> x >> y;
    vector<int> f(x + y + 1, 0); // 3-both 1-a 2-b
    
    int a = 1, b = 1, idx = 1;
    while (a <= x and b <= y) {
        // a / x < b / y
        // ay < bx
        if ((ll)a * y < (ll)b * x) {
            f[idx ++] = 1;
            a ++;
        }
        else if ((ll)a * y > (ll)b * x) {
            f[idx ++] = 2;
            b ++;
        }
        else {
            f[idx] = f[idx + 1] = 3;
            a += 1;
            b += 1;
            idx += 2;
        }
    }
    f[0] = f[x + y];
    
    while (q --) {
        int n;
        cin >> n;
        n %= (x + y);
        if (f[n] == 1) {
            cout << "Vanya" << endl;
        }
        else if (f[n] == 2) {
            cout << "Vova" << endl;
        }
        else {
            cout << "Both" << endl;
        }
    }
}