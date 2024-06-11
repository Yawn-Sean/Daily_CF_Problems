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
    ll p_n, p_w; cin >> p_n >> p_w;
    vector<PLL> arr(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    multiset<ll> more;
    int pre = n - 1, neg = 0, ans = n;
    while (1) {
        int j = upper_bound(arr.begin(), arr.end(), PLL(p_n, LLONG_MAX)) - arr.begin();
        ans = min(ans, (int)arr.size() - j - neg + 1);
        for (int i = j; i < pre; i++) {
            ll diff = arr[i].second - arr[i].first;
            more.insert(diff + 1);
        }
        pre = j;
        if (more.empty()) break;
        ll minn = *more.begin();
        more.erase(more.begin());
        if (p_n >= minn) p_n -= minn, neg += 1;
        else break;
    }
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
