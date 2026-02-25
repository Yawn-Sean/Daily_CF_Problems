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

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        long long total = (nums[0] + nums[n - 1]) / (n - 1);

        vector<long long> ans(n, 0);
        long long cur = 0;

        for (int i = 0; i < n - 1; i++) {
            ans[i] = -(nums[i] - nums[i + 1] - total) / 2 - cur;
            cur += ans[i];
        }

        ans[n - 1] = total - cur;

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}
