#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<long long> used_sum(5001, 0);
    used_sum[0] = 1;
    sort(nums.begin(), nums.end());
    int cur_sum = 0;
    long long ans = 0;
    for (int num : nums) {
        for (int i = cur_sum; i >= 0; --i) {
            if (used_sum[i]) {
                ans = (ans + used_sum[i] * max((i + num + 1LL) / 2, (long long)num)) % mod;
                ans %= mod;
                used_sum[i + num] += used_sum[i];
                used_sum[i + num] %= mod;
            }
        }
        cur_sum += num;
    }
    cout << ans << endl;
    return 0;
}
