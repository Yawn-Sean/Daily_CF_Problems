#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i + 1;
    }
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<>> pq;
    int ans = 0;
    int l = INT_MAX;
    int r = INT_MIN;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top() < a[i][0]) {
            pq.pop();
        }
        pq.push(a[i][1]);
        if (pq.size() > k) {
            pq.pop();
        }
        if (pq.size() == k) {
            if (ans < pq.top() - a[i][0] + 1) {
                ans = pq.top() - a[i][0] + 1;
                l = a[i][0];
                r = pq.top();
            }
        }
    }
    cout << ans << endl;
    if (ans == 0) {
        for (int i = 0; i < k; i++) {
            cout << i + 1 << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i][0] <= l && a[i][1] >= r) {
            cout << a[i][2] << " ";
            k--;
        }
        if (k == 0) return;
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