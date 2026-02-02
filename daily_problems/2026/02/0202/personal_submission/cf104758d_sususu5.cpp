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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> prefix(n), suffix(n);
    prefix[0] = INT_MIN, suffix[n - 1] = INT_MIN;
    for (int i = 1; i < n; i++) prefix[i] = max(prefix[i - 1], a[i - 1]);
    for (int i = n - 2; i >= 0; i--) suffix[i] = max(suffix[i + 1], a[i + 1]);
    for (int i = 1; i < n - 1; i++) a[i] = max(0, min(prefix[i], suffix[i]) - a[i]);
    ll ans = 0, cur = 0;
    for (int r = 1; r < n - 1; r++) {
        if (a[r] > 0) cur += a[r];
        else cur = 0;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}