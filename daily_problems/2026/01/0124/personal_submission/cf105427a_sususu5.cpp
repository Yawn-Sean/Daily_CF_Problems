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
    int n, k;
    cin >> n >> k;
    vector<ll> vals = {k + 1}, cnt = {1};
    while (vals.back() < n && vals.size() < k) {
        vals.emplace_back(k * vals.back() + 1);
        cnt.emplace_back(k * cnt.back() + 1);
    }
    int ans = max(n - vals.back(), 0LL);
    n -= ans;
    for (int i = vals.size() - 1; i >= 0; i--) {
        ans += n / vals[i] * cnt[i];
        n %= vals[i];
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