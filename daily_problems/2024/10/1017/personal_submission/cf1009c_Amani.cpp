#include <bits/stdc++.h>
using namespace std;

long double solve() {
    int n, m;
    cin >> n >> m;
    long double sum = 0;
    while (m--) {
        long double x, d;
        cin >> x >> d;
        sum += n * x;
        if (d >= 0) {
            sum += d * (n - 1) * n / 2.0;
        } else {
            if (n % 2 == 0) {
                long long k = n / 2;
                sum += d * (k * k);
            } else {
                long long k = (n + 1) / 2;
                sum += d * (k * (k - 1));
            }
        }
    }
    return sum / n;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15) << solve() << endl;
    return 0;
}
