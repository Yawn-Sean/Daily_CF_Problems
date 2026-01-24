#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> nums(n);
        for(auto &x:nums) cin>>x;

        if (k != n - 1) {
            long long res=0;
            for (int i = 0; i < n; ++i) {
                res += nums[i];
                res%=n;
            }
            cout << (n-res)%n << "\n";
        } else {
            vector<long long> cnt(n, 0);
            for (long long x : nums) {
                cnt[(n-x%n)%n]++;
            }

            long long cur = 0;
            for (int i = 0; i < n; ++i) {
                cur += (long long)i * cnt[i];
            }

            long long ans = cur;
            for (int i = 0; i < n; ++i) {
                cur += 1ll* n * cnt[i];
                cur -= n;
                ans = min(ans, cur);
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
