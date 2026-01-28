#include <algorithm>
#include <bit>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <stack>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <numbers>
#include <cmath>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MOD = 1e9 + 7;

ll query(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    ll x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

void report(ll m) {
    cout << "! " << m << '\n';
    cout.flush();
}

void solve() {
    ll sx, sy, tx, ty, k;
    cin >> sx >> sy >> tx >> ty >> k;
    ll dx = abs(sx - tx), dy = abs(sy - ty);
    if (dx > dy) swap(dx, dy);
    if ((dx + 1) * k >= dy) {
        cout << dx + dy << '\n';
        return;
    }

    ll ans = 0;
    ans += dx;
    ans += dy;
    dy -= (dx + 1) * k;
    ll extra = (dy + k - 1) / k;
    extra = ((extra + 1) / 2) * 2;
    ans += extra;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}