#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;
int inf = 2e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int cur = 0;
    vector<int> w(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i];
        cur += w[i];
    }

    // 假设H是固定值
    // <=n/2个被翻转
    int limit = n / 2;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return w[i] - h[i] > w[j] - h[j];
    });

    int ans = inf;
    vector<int> used(n);
    for (int ht = 1; ht <= 1000; ht++) {
        bool ok = true;
        int cnt = 0, cur_w = cur;
        for (auto& i: order) {
            if (h[i] > ht) {
                if (w[i] > ht) {
                    ok = false;
                    break;
                } else {
                    used[i] = 1;
                    cnt++;
                    cur_w += h[i] - w[i];
                }
            } else {
                used[i] = 0;
            }
        }
        
        if (cnt > limit || !ok) {
            continue;
        }

        for (auto& i: order) {
            if (!used[i] && cnt < limit && w[i] <= ht && w[i] - h[i] > 0) {
                cnt++;
                cur_w += h[i] - w[i];
            }
        }
        ans = min(ans, cur_w * ht);
    }
    cout << ans << endl;
    return 0;
}
