#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a < b) printf("-1\n");
    else {
        double x = (a + b) / (2.0 * ((a + b) / (2 * b)));
        printf("%.12lf\n", x);
    }
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
