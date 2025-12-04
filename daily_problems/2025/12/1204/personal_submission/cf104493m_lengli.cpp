#include <bits/stdc++.h>
using namespace std;
#define M_PI		3.14159265358979323846

using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;  
    cin >> t;
    while (t--) {
        ld r, n, l;
        cin >> r >> n >> l;

        ld ans = M_PI * r * r;
        ans += l * r * n;
        ans += (l * l / 2.0) / tan(M_PI / n) * (n / 2.0);

        cout << fixed << setprecision(15) << ans << "\n";
    }

    return 0;
}
