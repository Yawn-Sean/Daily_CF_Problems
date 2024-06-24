#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> last(n, n);
    map<int, int> mp;
    for (int i = n - 1; i >= 0; i--) {
        if (mp.count(a[i])) {
            last[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }
    mp.clear();
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        if (mp.count(a[i])) {
            mp[a[i]] = last[i];
            pq.push({last[i], a[i]});
            continue;
        }
        ans++;
        while (!pq.empty() && !mp.count(pq.top().second)) pq.pop();
        if (mp.size() < k) {
            mp[a[i]] = last[i];
            pq.push({last[i], a[i]});
        } else {
            auto [_, idx] = pq.top();
            pq.pop();
            mp.erase(idx);
            mp[a[i]] = last[i];
            pq.push({last[i], a[i]});
        }
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