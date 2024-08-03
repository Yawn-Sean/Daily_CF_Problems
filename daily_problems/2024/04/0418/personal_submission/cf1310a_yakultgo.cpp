#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;
    sort(a.begin(), a.end());
    priority_queue<int> pq;
    ll ans = 0;
    ll sum = 0;
    int pre = 0;
    for (int i = 0; i < n; pre++) {
        if (pq.size() == 0) {
            pre = a[i].first;
        }
        while (i < n && a[i].first == pre) {
            pq.push(a[i].second);
            sum += a[i].second;
            i++;
        }
        sum -= pq.top();
        pq.pop();
        ans += sum;
    }
    while (pq.size()) {
        sum -= pq.top();
        pq.pop();
        ans += sum;
    }
    cout << ans << endl;
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