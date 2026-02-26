#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 2e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll b;
    cin >> n >> b;

    vector<ll> xs(n), ys(n);
    for (int i = 0; i < n; i++) cin >> xs[i];
    for (int i = 0; i < n; i++) cin >> ys[i];

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return ys[a] > ys[b];
    });

    for (int i = 0; i < n; i++) {
        int idx = order[i];
        ll x = xs[idx];
        ll y = ys[idx];
        for (int j = i; j >= 0; j--) {
            if (dp[j] != INF) {
                dp[j + 1] = min(dp[j + 1], dp[j] + x + y * j);
            }
        }
    }

    for (int i = n; i >= 0; i--) {
        if (dp[i] <= b) {
            cout << i << " " << dp[i] << "\n";
            break;
        }
    }

    return 0;
}
