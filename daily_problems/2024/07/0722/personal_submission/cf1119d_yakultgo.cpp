#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    auto cmp = [&](pair<ll, int> &t1, pair<ll, int> &t2) -> bool {
        if (t1.first == t2.first) return t1.second > t2.second;
        return t1.first > t2.first;
    };
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, decltype(cmp)> pq(cmp);
    for (int i = 1; i < n; i++) {
        pq.push({a[i] - a[i - 1], 0});
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll l, r;
        cin >> l >> r;
        pq.push({r - l + 1, i});
    }
    ll sum = 0, cnt = 0;
    vector<ll> ans(q + 1);
    while (!pq.empty()) {
        auto [diff, idx] = pq.top();
        pq.pop();
        if (idx == 0) {
            sum += diff;
            cnt++;
        } else {
            ans[idx] = 1ll * (n - cnt) * diff + sum;
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}