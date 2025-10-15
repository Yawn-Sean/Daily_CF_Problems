#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M = 1e6 + 1;
    vector<bool> used(M, 0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (auto &x: nums) cin >> x;

        vector<int> ans;
        for (int i = 1; i < M; i ++) {
            if (!used[i]) {
                used[i] = 1;
                ans.emplace_back(i);

                for (int j = 0; j < n; j ++) {
                    for (int k = 0; k < j; k ++) {
                        int v = i + abs(nums[j] - nums[k]);
                        if (v < M) used[v] = 1;
                    }
                }

                if (ans.size() == n) break;
            }
        }

        for (int i = 1; i < M; i ++)
            used[i] = 0;

        cout << "YES\n";
        for (auto &x: ans) cout << x << ' '; cout << '\n';
    }

    return 0;
}
