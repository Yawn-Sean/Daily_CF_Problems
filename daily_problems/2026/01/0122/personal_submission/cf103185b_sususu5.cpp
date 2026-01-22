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
    vector<int> start_inc(n, 1), end_dec(n, 1);
    int pos = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == -1) {
            if (i + 1 < n) start_inc[i] = start_inc[i + 1] + 1;
        } else {
            if (pos != -1) {
                if (a[i] <= a[pos]) start_inc[i] = start_inc[i + 1] + 1;
                else start_inc[i] = pos - i;
            } else if (i < n - 1) {
                start_inc[i] = start_inc[i + 1] + 1;
            }
            pos = i;
        }
    }
    pos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            if (i > 0) end_dec[i] = end_dec[i - 1] + 1;
        } else {
            if (pos != -1) {
                if (a[i] <= a[pos]) end_dec[i] = end_dec[i - 1] + 1;
                else end_dec[i] = i - pos;
            } else if (i > 0) {
                end_dec[i] = end_dec[i - 1] + 1;
            }
            pos = i;
        }
    }
    for (int k = 3; k <= n; k++) {
        bool valid = true;
        for (int l = 0; l < n; l += k) {
            int r = min(n - 1, l + k - 1);
            int len = r - l + 1;
            int prefix = start_inc[l], suffix = end_dec[r];
            if (prefix + suffix < len + 1 || len < 3 || prefix < 2 || suffix < 2) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << "Y\n";
            return;
        }
    }
    cout << "N\n";
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