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
    vector<PII> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += (ll)a[i].second * n - a[i].first;
    sort(a.begin(), a.end(), [&](PII &i, PII &j) -> bool {
        return i.first - i.second > j.first - j.second;
    });
    for (int i = 0; i < n; i++) ans += (ll)(a[i].first - a[i].second) * (i + 1);
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
