#include <bits/stdc++.h>
#include <cmath>

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
// #define double long double
// #define acos acosl
// #define sqrt sqrtl
// #define sin sinl
// #define cos cosl
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
const double PI = acos(-1);
void solve() {
    int n;
    double r;
    cin >> n >> r;
    double minD = r;
    while (n--) {
        double a, b, c;
        cin >> a >> b >> c;
        minD = min(minD, abs(c) / sqrt(a * a + b * b));
    }
    double theta = 2 * acos(minD / r);
    double S = PI * r * r;
    double S1 = r * r * theta / 2;
    double S2 = r * sin(theta / 2) * r * cos(theta / 2);
    double S3 = S1 - S2;
    double S4 = S - S3;
    cout << fixed << setprecision(15) << S3 / S << ' ' << S4 / S << endl;
}

signed main() {
    IOS;
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}