#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> y(n);
    for (int i = 0; i < n; ++i) cin >> y[i];
    auto par = [](int x1, int y1, int x2, int y2) -> bool {
        int g1 = gcd(x1, y1), g2 = gcd(x2, y2);
        x1 /= g1; y1 /= g1;
        x2 /= g2; y2 /= g2;
        return (x1 == x2 && y1 == y2) || (x1 == -x2 && y1 == -y2);
    };
    auto check = [&](int x1, int x2) -> bool {
        int X1 = x2 - x1, Y1 = y[x2] - y[x1];
        int x0 = -1, X2 = 0, Y2 = 0;
        for (int i = 0; i < n; ++i) if (i != x1) {
            if (!par(X1, Y1, i - x1, y[i] - y[x1])) {
                if (x0 < 0) {
                    x0 = i;
                } else if (!X2) {
                    X2 = i - x0; Y2 = y[i] - y[x0];
                    if (!par(X1, Y1, X2, Y2)) return false;
                } else if (!par(X2, Y2, i - x0, y[i] - y[x0])) return false;
            }
        }
        return x0 >= 0;
    };
    println("{}", check(0, 1) || check(0, 2) || check(1, 2) ? "Yes" : "No");
}


int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
