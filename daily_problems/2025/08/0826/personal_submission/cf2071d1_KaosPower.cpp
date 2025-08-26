//  D1. Infinite Sequence (Easy Version)

#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        long long l, r;
        cin >> n >> l >> r;

        vector<int> nums(n);
        for (auto &x: nums) cin >> x;

        if (n % 2 == 0) {
            int v = 0;
            for (int i = 0; i < n / 2; i ++)
                v ^= nums[i];
            nums.emplace_back(v);
            n ++;
        }

        int total = 0;
        for (auto &v: nums) total ^= v;

        auto solve = [&] (auto &self, long long x) -> int {
            if (x <= n) return nums[x - 1];

            if (x <= n * 2) {
                int ans = 0;
                for (int i = 0; i < x / 2; i ++)
                    ans ^= nums[i];
                return ans;
            }

            long long v = x / 2;
            if (v % 2 == 0) return total ^ self(self, v);
            return total;
        };

        cout << solve(solve, l) << '\n';
    }

    return 0;
}
