/*
假如出现在上升段：a - b = k * x，k 为偶数，x >= b，(a - b) / k >= b，k <= (a - b) / b
假如出现在下降段：a + b = 截距，a + b = k * x，k 为偶数，x >= b，k <= (a + b) / b
*/

int T;
LL a, b;

void solve1() {
    cin >> a >> b;
    if (a < b) {
        cout << "-1\n";
        return;
    }

    double res = INFLL;
    LL up = a - b;
    LL k = (a - b) / b;
    if (k & 1) {
        k--;
    }
    if (k > 0) {
        res = min(res, up / (1.0 * k));
    }
    LL down = a + b;
    k = (a + b) / b;
    if (k & 1) {
        k--;
    }
    if (k > 0) {
        res = min(res, down / (1.0 * k));
    }
    cout << setprecision(15) << res << "\n";
}                                                                                                                  
