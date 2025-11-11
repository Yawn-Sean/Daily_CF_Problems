#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        long long ans = 0;
        int width = 2 * n + 5;
        vector<vector<long long>> cnt(2, vector<long long>(width, 0));
        int cur = n + 2;
        int msk = 0;

        for (int x : nums) {
            cnt[msk][cur]++;

            if (x % 2) {
                msk ^= 1; 
                cur -= 1;
            } else {
                cur += 1;
            }
            ans += cnt[msk][cur - 1] + cnt[msk ^ 1][cur + 1];
        }

        cout << ans << '\n';
    }

    return 0;
}
