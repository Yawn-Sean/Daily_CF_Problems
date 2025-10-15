#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<int> d(m), h(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i] >> h[i];
    }

    auto check = [&]() {
        bool ans = false;
        int ans_h = -1;
        for (int i = 1; i < m; i++) {
            int diff = d[i] - d[i - 1];
            int h_diff = h[i] - h[i - 1];
            if (abs(h_diff) > diff) {
                return -1;
            }
            // place the answer x between d[i - 1] and d[i]
            ans_h = max(ans_h, max(h[i], h[i - 1]) + (diff - abs(h_diff)) / 2);
        }

        // first d
        ans_h = max(ans_h, h[0] + d[0] - 1);

        // after last d
        ans_h = max(ans_h, h[m - 1] + (n - d[m - 1]));
        return ans_h;
    };

    i64 ans = check();
    if (ans == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << ans;
    }
    return 0;
}
