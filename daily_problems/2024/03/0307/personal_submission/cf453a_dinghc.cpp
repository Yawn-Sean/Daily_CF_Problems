#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

double fast_pow(double a, int b) {
    double res = 1.0;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    cout << fixed << setprecision(12);

    int m, n;
    cin >> m >> n;

    // ans = (m*(m^n - (m-1)^n) + (m-1)*((m-1)^n - (m-2)^n) + ... + 2*(2^n - 1) + 1) / m^n
    double ans = m;
    for (int i = 1; i < m; i++) {
        ans -= fast_pow(static_cast<double>(i) / m, n);
    }

    cout << ans << endl;

    return 0;
}
