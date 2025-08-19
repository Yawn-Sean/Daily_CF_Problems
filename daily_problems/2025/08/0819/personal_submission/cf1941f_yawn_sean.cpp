#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> nums(n), v1(m), v2(k);

        for (auto &x: nums) cin >> x;
        for (auto &x: v1) cin >> x;
        for (auto &x: v2) cin >> x;

        sort(v2.begin(), v2.end());

        int max_gap = 0, max_gap_cnt = 0;

        for (int i = 1; i < n; i ++) {
            if (nums[i] - nums[i - 1] > max_gap) {
                max_gap = nums[i] - nums[i - 1];
                max_gap_cnt = 1;
            }
            else if (nums[i] - nums[i - 1] == max_gap)
                max_gap_cnt ++;
        }

        if (max_gap_cnt > 1) cout << max_gap << '\n';
        else {
            int other_gap = 0;
            for (int i = 1; i < n; i ++) {
                if (nums[i] - nums[i - 1] < max_gap) {
                    other_gap = max(other_gap, nums[i] - nums[i - 1]);
                }
            }

            for (int i = 1; i < n; i ++) {
                if (nums[i] - nums[i - 1] == max_gap) {
                    int to_search = nums[i - 1] + (nums[i] - nums[i - 1]) / 2; // 我就是不用 long long 哼
                    int ans = max_gap;

                    for (auto &x: v1) {
                        int p = lower_bound(v2.begin(), v2.end(), to_search - x) - v2.begin();
                        for (int j = p - 1; j <= p + 1; j ++) {
                            if (j >= 0 && j < k && v2[j] + x >= nums[i - 1] && v2[j] + x <= nums[i]) {
                                ans = min(ans, max((v2[j] + x) - nums[i - 1], nums[i] - (v2[j] + x)));
                            }
                        }
                    }
                    ans = max(ans, other_gap);
                    cout << ans << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}