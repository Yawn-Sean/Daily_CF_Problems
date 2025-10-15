#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;
i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    vector<int> ans(n);
    priority_queue<pair<int, int>> pq; // {value, index}
    for (int i = 0; i < n; i++) {
        int idx = order[i];
        if (!pq.empty() && -pq.top().first < a[idx] - d) {
            auto [value, index] = pq.top();
            // cout << "Popping: " << -value << " at index " << index << endl;
            pq.pop();
            ans[idx] = index;
            pq.push({-a[idx], index});
        } else {
            int sz = pq.size();
            ans[idx] = sz + 1; // Assign a new index
            // cout << "Pushing: " << a[idx] << " at new index " << sz + 1 << endl;
            pq.push({-a[idx], sz + 1});
        }
    }

    int mx = *max_element(ans.begin(), ans.end());
    cout << mx << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
