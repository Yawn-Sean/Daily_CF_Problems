#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> xs(n), ys(n), ts(n);
    vector<long double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i] >> ys[i] >> ts[i] >> p[i];
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return ts[i] < ts[j];
    });

    // 最后射击目标为 i时的最优期望
    vector<long double> dp(n, 0.0);
    for (int i = 0; i < n; i++) {
        int i_idx = order[i];
        for (int j = 0; j < i; j++) {
            int j_idx = order[j];

            i64 dist = 1ll * (xs[i_idx] - xs[j_idx]) * (xs[i_idx] - xs[j_idx]) + 1ll * (ys[i_idx] - ys[j_idx]) * (ys[i_idx] - ys[j_idx]);
            i64 time_diff = 1ll * (ts[i_idx] - ts[j_idx]) * (ts[i_idx] - ts[j_idx]);
            if (time_diff >= dist) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += p[i_idx];
    }

    cout << fixed << setprecision(10) << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
