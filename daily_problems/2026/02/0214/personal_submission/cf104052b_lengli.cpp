#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<long long> outs;

    vector<vector<int>> tmp = {
        {2, 1, 1, 0},
        {2, 0, 2, 0},
        {1, 1, 2, 1}
    };

    const long long inf = 1e9;

    while (t--) {
        vector<long long> nums(4);
        for (int i = 0; i < 4; i++) {
            cin >> nums[i];
        }

        long long ans = inf;
        for (int i = 0; i < 16; i++) {

            long long cur = 0;
            for (int j = 0; j < 4; j++) {
                if ((i >> j) & 1) {
                    cur += nums[j];
                }
            }

            long long to_check = inf;

            for (int j = 0; j < 3; j++) {
                long long val = 0;
                for (int k = 0; k < 4; k++) {
                    if ((i >> k) & 1) {
                        val += tmp[j][k];
                    }
                }
                to_check = min(to_check, val);
            }

            if (to_check) {
                ans = min(ans, cur / to_check);
            }
        }

        outs.push_back(ans);
    }

    for (int i = 0; i < (int)outs.size(); i++) {
        if (i) cout << '\n';
        cout << outs[i];
    }

    return 0;
}
