#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

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