#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<string> outs;

    while (t--) {
        int n;
        long long b;
        cin >> n >> b;

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        long long sum = 0;
        for (auto x : nums) sum += x;

        if (sum % (b - 1) != 0) {
            outs.push_back("NO");
        } else {
            outs.push_back("YES");

            vector<long long> res;
            long long cur = 0;

            for (auto x : nums) {
                cur = cur * b + x;
                res.push_back(cur / (b - 1));
                cur %= (b - 1);
            }

            outs.push_back(to_string(n + 2));

            // line: 1 0 res...
            {
                ostringstream oss;
                oss << "1 0";
                for (auto v : res) oss << ' ' << v;
                outs.push_back(oss.str());
            }

            // line: 1 res... 0
            {
                ostringstream oss;
                oss << "1";
                for (auto v : res) oss << ' ' << v;
                oss << " 0";
                outs.push_back(oss.str());
            }
        }
    }

    for (size_t i = 0; i < outs.size(); i++) {
        cout << outs[i];
        if (i + 1 < outs.size()) cout << '\n';
    }

    return 0;
}
