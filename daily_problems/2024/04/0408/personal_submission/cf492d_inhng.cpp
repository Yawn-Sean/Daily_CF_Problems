#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, x, y, num;
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        int left = 0, right = 1e18;
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            if (mid / x + mid / y >= num) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if ((left + 1) % x == 0 and (left + 1) % y == 0) {
            cout << "Both\n";
        } else if ((left + 1) % y == 0) {
            cout << "Vanya\n";
        } else {
            cout << "Vova\n";
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
 
