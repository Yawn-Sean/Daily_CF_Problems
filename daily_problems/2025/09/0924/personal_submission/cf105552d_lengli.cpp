#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long double r;
    cin >> n >> r;

    const long double PI = acosl(-1.0L);

    long double mi_d = r;  
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        long double denom = hypotl((long double)a, (long double)b);
        if (denom > 0) {
            long double d = fabsl((long double)c) / denom;
            mi_d = min(mi_d, d);
        }
    }

    long double x = (r == 0 ? 1.0L : mi_d / r);
    x = clamp(x, -1.0L, 1.0L);

    long double theta = acosl(x);
    long double v1 = theta - sinl(theta) * cosl(theta);
    v1 /= PI;

    cout.setf(std::ios::fixed); 
    cout << setprecision(15) << v1 << ' ' << (1.0L - v1);
    return 0;
}
