#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    vector<string> outs;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        vector<int> v1, v2;
        int half = n / 2;
        for (int i = 0; i < n; ++i) {
            bool cond = (i < half) ^ (nums[i] <= half);
            if (cond) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }

        if (!v1.empty() && !v2.empty()) {
            outs.push_back("2");

            // build line for v1
            {
                ostringstream oss;
                oss << v1.size();
                for (int x : v1) oss << ' ' << x;
                outs.push_back(oss.str());
            }

            // build line for v2
            {
                ostringstream oss;
                oss << v2.size();
                for (int x : v2) oss << ' ' << x;
                outs.push_back(oss.str());
            }
        } else {
            ostringstream oss;
            oss << 1;
            outs.push_back(oss.str());

            ostringstream oss2;
            oss2 << n;
            for (int x : nums) oss2 << ' ' << x;
            outs.push_back(oss2.str());
        }
    }

    // print all outputs
    for (size_t i = 0; i < outs.size(); ++i) {
        cout << outs[i];
        if (i + 1 < outs.size()) cout << '\n';
    }

    return 0;
}
