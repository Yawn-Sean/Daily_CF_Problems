#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

ld get_dist(int x1, int y1, int x2, int y2) {
    ld x = x1 - x2;
    ld y = y1 - y2;
    return sqrtl(x * x + y * y);
}

void solve() { 
    int ax, ay, bx, by, tx, ty; cin >> ax >> ay >> bx >> by >> tx >> ty;
    int n; cin >> n;
    ld ans = 0, dp1 = INT_MAX, dp2 = INT_MAX, dp3 = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        ld t = get_dist(x, y, tx, ty);
        ans += t * 2;
        ld v1 = get_dist(x, y, ax, ay) - t, v2 = get_dist(x, y, bx, by) - t;
        dp3 = min(dp3, min(dp1 + v2, dp2 + v1));
        dp2 = min(dp2, v2);
        dp1 = min(dp1, v1);
    }
    printf("%.15Lf\n", ans + min(dp1, min(dp2, dp3)));
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
