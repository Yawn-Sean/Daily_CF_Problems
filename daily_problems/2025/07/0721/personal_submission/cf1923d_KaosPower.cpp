#include<bits/stdc++.h>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (auto &v: nums) cin >> v;

        vector<long long> acc(n + 1, 0);
        for (int i = 0; i < n; i ++)
            acc[i + 1] = acc[i] + nums[i];

        vector<int> last_pos(n), next_pos(n);
        iota(last_pos.begin(), last_pos.end(), 0);
        iota(next_pos.begin(), next_pos.end(), 0);

        for (int i = 1; i < n; i ++)
            if (nums[i] == nums[i - 1])
                last_pos[i] = last_pos[i - 1];

        for (int i = n - 2; i >= 0; i --)
            if (nums[i] == nums[i + 1])
                next_pos[i] = next_pos[i + 1];

        vector<int> ans(n, n);
        for (int i = 0; i < n; i ++) {
            if (i) {
                int l = 0, r = i - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (acc[i] - acc[mid] > nums[i]) l = mid + 1;
                    else r = mid - 1;
                }
                r = min(r, last_pos[i - 1] - 1);
                if (r >= 0) ans[i] = min(ans[i], i - r);
                if (nums[i - 1] > nums[i]) ans[i] = 1;
            }
            if (i + 1 < n) {
                int l = i + 1, r = n - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (acc[mid + 1] - acc[i + 1] > nums[i]) r = mid - 1;
                    else l = mid + 1;
                }
                l = max(l, next_pos[i + 1] + 1);
                if (l < n) ans[i] = min(ans[i], l - i);
                if (nums[i + 1] > nums[i]) ans[i] = 1;
            }
            if (ans[i] == n) ans[i] = -1;
        }
        for (auto &x: ans) cout << x << ' '; cout << '\n';
    }

    return 0;
}
