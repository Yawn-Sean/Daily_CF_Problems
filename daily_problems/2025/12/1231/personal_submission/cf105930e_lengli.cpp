#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<long long> outs;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        long long ma = *max_element(nums.begin(), nums.end());

        vector<long long> acc_cnt(ma + 1, 0);
        for (long long x : nums) {
            acc_cnt[x]++;
        }

        // 前缀和
        for (int i = 0; i < ma; i++) {
            acc_cnt[i + 1] += acc_cnt[i];
        }

        long long total = k;
        for (long long x : nums) total += x;

        auto check = [&](long long x) -> bool {
            if (x >= ma) {
                return acc_cnt[ma] * x <= total;
            }

            long long val = 0;
            for (long long i = 0; i <= ma; i += x) {
                long long l = i;
                long long r = min(i + x, ma);
                val += (acc_cnt[r] - acc_cnt[l]) * (i + x);
                if (val > total) return false; // 小剪枝
            }
            return val <= total;
        };

        long long ans = 0;

        for (long long i = 1; i * i <= total; i++) {
            if (total % i == 0) {
                if (check(i)) ans = max(ans, i);
                long long j = total / i;
                if (j != i && check(j)) ans = max(ans, j);
            }
        }

        outs.push_back(ans);
    }

    for (size_t i = 0; i < outs.size(); i++) {
        cout << outs[i];
        if (i + 1 < outs.size()) cout << '\n';
    }

    return 0;
}
