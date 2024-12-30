#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i ++) {
        nums[i] = min(nums[i], (i ? nums[i - 1] : 0) + 1);
    }
    for (int i = n - 1; i >= 0; i --) {
        nums[i] = min(nums[i], (i == n - 1 ? 0 : nums[i + 1]) + 1);
    }

    int ans = 1;
    for (int i = 0; i < n; i ++) {
        ans = max(ans, nums[i]);
    }

    cout << ans << "\n";

}

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T{1};
    // cin >> T;
    
    while (T--) {
        solve();
    }

}