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
        cin >> n;

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        bool found = false;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                outs.push_back(nums[i] / (nums[i + 1] - 1));
                found = true;
                break;
            }
        }

        if (!found) {
            long long a = nums[n - 1] - nums[n - 2];
            long long b = nums[n - 1] / (nums[n - 1] - nums[n - 2]);
            outs.push_back(max(a, b));
        }
    }

    for (auto x : outs) {
        cout << x << '\n';
    }

    return 0;
}
