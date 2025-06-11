#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    int idx = 1;
    int rank = n + 1;
    sort(a.begin() + 1, a.end(), [](pair<ll, ll> t1, pair<ll, ll> t2) {
        return t1.first > t2.first;
    });
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while (true) {
        while (idx < n && a[idx].first > a[0].first) {
            pq.push(a[idx].second - a[idx].first + 1);
            idx++;
        }
        rank = min(rank, (int)pq.size() + 1);
        if (!pq.empty() && pq.top() <= a[0].first) {
            a[0].first -= pq.top();
            pq.pop();
        } else {
            break;
        }
    }
    cout << rank << endl;
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