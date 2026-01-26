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
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (int& val : a) cin >> val;
    ranges::sort(a);
    for (int k = 1; k <= n; k++) {
        int idx = 0, width = k;
        for (int j = 0; j < m; j++) {
            int val = a[idx + width - 1];
            cout << val << ' ';
            auto it_begin = a.begin() + idx;
            auto it_end = a.begin() + idx + width;
            auto it = lower_bound(it_begin, it_end, val);
            idx += width;
            width = distance(it, it_end);
        }
        cout << '\n';
    }
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