#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({a[i], i});
    }
    vector<ll> ans(n, -1);
    while (pq.size() >= 2) {
        auto [x, i] = pq.top();
        pq.pop();
        auto [y, j] = pq.top();
        pq.pop();
        if (x == y) {
            pq.push({2ll * x, j});
            a[j] = 2ll * x;
        } else {
            ans[i] = x;
            pq.push({y, j});
        }
    }
    if (!pq.empty()) {
        auto [x, i] = pq.top();
        ans[i] = x;
    }
    vector<ll> ret;
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1)
            ret.push_back(ans[i]);
    }
    cout << ret.size() << endl;
    for (auto x : ret) {
        cout << x << " ";
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