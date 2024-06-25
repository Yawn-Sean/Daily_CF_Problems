#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans = 0, pre = -1;
    cin >> n >> k;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            k--, ans += 2;
            if (pre != -1) pq.push(i - pre - 1);
            pre = i;
        }
    }
    if (k < 0) {
        cout << "-1\n";
        return;
    }
    if (pre == -1) {
        cout << "0\n";
        return;
    }
    int t1 = 0, k1 = k, t2 = 1, k2 = k - (n - 1 - pre);
    while (!pq.empty() && pq.top() <= k1) {
        k1 -= pq.top(), t1 += 2;
        if (pq.top() <= k2) k2 -= pq.top(), t2 += 2;
        pq.pop();
    }

    ans = ans - (k2 >= 0 ? max(t1, t2) : t1);
    cout << ans << "\n";

    return 0;
}
