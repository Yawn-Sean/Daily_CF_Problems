#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int min_delta = 1e9;
    int ans = 0;

    for (int pos = k; pos < nums.size(); pos++) {
        int delta = nums[pos] - nums[pos - k];
        if (delta < min_delta) {
            min_delta = delta;
            ans = (nums[pos] + nums[pos - k]) / 2;
        }
    }

    cout << ans << "\n";
}

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T{1};
    cin >> T;
    while (T--) {
        solve();
    }

}