#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
bool cmp(pair<ll, int> &a, pair<ll, int> &b) {
    return abs(a.first) > abs(b.first);
}
void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, decltype(cmp) *> pq(cmp);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            cnt++;
        pq.push({abs(a[i]), i});
    }
    while (!pq.empty() && k) {
        auto [val, idx] = pq.top();
        pq.pop();
        if (a[idx] < 0) {
            if (cnt % 2 == 0) {
                a[idx] += x;
                if (a[idx] >= 0)
                    cnt--;
            } else {
                a[idx] -= x;
            }
        } else {
            if (cnt % 2 == 0) {
                a[idx] -= x;
                if (a[idx] < 0)
                    cnt++;
            } else {
                a[idx] += x;
            }
        }
        pq.push({abs(a[idx]), idx});
        k--;
    }
    for (auto &i : a) cout << i << " ";
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