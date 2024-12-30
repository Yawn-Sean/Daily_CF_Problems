#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x, neg = 0;
    cin >> n >> k >> x;
    vector<long long> a(n);
    priority_queue<pair<long long, int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.emplace(-abs(a[i]), i);
        if (a[i] < 0) neg++;
    }

    if (neg % 2 == 0) {
        auto [val, idx] = pq.top(); pq.pop();
        long long c = min(-val / x + 1, 1LL * k);
        a[idx] = (a[idx] < 0 ? a[idx] + c * x : a[idx] - c * x);
        k -= c;
        pq.emplace(-abs(a[idx]), idx);
    }

    while (k--) {
        int idx = pq.top().second; pq.pop();
        a[idx] = (a[idx] < 0 ? a[idx] - x : a[idx] + x);
        pq.emplace(-abs(a[idx]), idx);
    }

    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';

    return 0;
}
