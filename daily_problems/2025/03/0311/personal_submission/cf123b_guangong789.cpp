#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    int X1 = x1 + y1;  // |x+y|=0(mod 2a) -> |x|=0(mod 2a)
    int Y1 = x1 - y1;  // |x-y|=0(mod 2b) -> |y|=0(mod 2b)
    int X2 = x2 + y2;
    int Y2 = x2 - y2;

    X1 = X1 / (2*a) + (X1 > 0);
    Y1 = Y1 / (2*b) + (Y1 > 0);
    X2 = X2 / (2*a) + (X2 > 0);
    Y2 = Y2 / (2*b) + (Y2 > 0);

    cout << max(abs(X1 - X2), abs(Y1 - Y2));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}