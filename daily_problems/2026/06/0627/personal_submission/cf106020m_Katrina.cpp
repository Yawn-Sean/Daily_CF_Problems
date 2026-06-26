#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<long long> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + a[i];
        }

        long long ans = 0;
        ans ^= pre[n];
        if (n >= 2) ans ^= pre[n - 1];
        if (n >= 2) ans ^= (pre[n] - pre[1]);
        if (n >= 3) ans ^= (pre[n - 1] - pre[1]);
        cout << ans << "\n";
    }

    return 0;
}
