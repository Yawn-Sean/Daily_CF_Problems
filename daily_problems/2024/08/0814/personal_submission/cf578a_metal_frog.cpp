#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    int a, b;
    cin >> a >> b;
    if (a >= b) {
        double ans = 1e9;
        int tmp = a - b;
        if (tmp >= 2 * b) {
            int k = tmp / (2 * b);
            ans = min(ans, 1.0 * tmp / 2 / k);
        }
        tmp = a + b;
        if (tmp >= 2 * b) {
            int k = tmp / (2 * b);
            ans = min(ans, 1.0 * tmp / 2 / k);
        }
        cout << setprecision(12) << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
