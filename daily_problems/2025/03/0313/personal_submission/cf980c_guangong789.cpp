#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    vector<int> ans(256, -1);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int mn, tmp;
    for (int &i : vec) {
        if (ans[i] == -1) {
            tmp = i - k + 1;
            mn = (tmp >= 0) ? tmp : 0;
            for (int j = mn; j <= i; ++j) {
                if (ans[j] == -1 || ans[j] == j) {
                    for (int t = j; t <= i; ++t) {
                        ans[t] = j;
                    }
                }
            }
        }
        cout << ans[i] << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}