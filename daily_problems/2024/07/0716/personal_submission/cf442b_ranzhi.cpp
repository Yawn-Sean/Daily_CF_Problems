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

void solve() {
    int n; cin >> n;
    vector<ld> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.rbegin(), arr.rend());
    ld p0 = 1, p1 = 0, ans = 0;
    for (auto &x : arr) {
        p1 = x * (p0 - p1) + p1;
        p0 *= (1 - x);
        ans = max(ans, p1);
        if (p0 < p1) break;
    }
    printf("%.15Lf\n", ans);
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
