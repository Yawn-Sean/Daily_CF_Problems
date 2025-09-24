#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    long double r;
    cin >> n >> r;

    long double mi_d = r;

    while (n --) {
        int a, b, c;
        cin >> a >> b >> c;
        mi_d = min(mi_d, (long double)1 * abs(c) / sqrtl(a * a + b * b));
    }

    long double theta = acosl(mi_d / r);
    long double v1 = theta - sinl(theta) * cosl(theta);
    v1 /= acosl(-1);

    cout << fixed << setprecision(15) << v1 << ' ' << 1 - v1;

    return 0;
}
