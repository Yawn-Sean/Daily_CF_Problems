#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int ax, ay, bx, by, tx, ty, n;
    double ans = 0, cnt1 = INF, cnt2 = INF, cnt3 = INF;
    cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        ans += 2 * hypot(x - tx, y -ty);
        cnt3 = min({cnt3, cnt1 + hypot(x - bx, y - by) - hypot(x - tx, y -ty), cnt2 + hypot(x - ax, y - ay) - hypot(x - tx, y -ty)});
        cnt1 = min(cnt1, hypot(x - ax, y - ay) - hypot(x - tx, y -ty));
        cnt2 = min(cnt2, hypot(x - bx, y - by) - hypot(x - tx, y -ty));
    }
    cout << ans + min({cnt1, cnt2, cnt3}) << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
