#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        int n;
        cin >> n;
        if (!n) break;

        vector<int> nums(n);
        int total = 0;
        for (auto &v: nums)
            cin >> v, total += v;

        if (total & 1) cout << "No\n";
        else {
            vector<int> ans(n);

            vector<int> idxs;
            int even_idx = -1;

            for (int i = 0; i < n; i ++) {
                if (nums[i] & 1) idxs.emplace_back(i);
                else if (even_idx == -1) even_idx = i;
                else ans[i] = nums[i] / 2;
            }

            if (even_idx >= 0) {
                cout << "Yes\n";
                idxs.emplace_back(even_idx);

                int cur = 0;
                for (auto &i: idxs) cur = nums[i] - cur;

                cur /= 2;
                for (auto &i: idxs) {
                    ans[i] = cur;
                    cur = nums[i] - cur;
                }

                for (int i = 0; i < n; i ++)
                    cout << ans[i] << ' ';
                cout << '\n';
                for (int i = 0; i < n; i ++)
                    cout << nums[i] - ans[i] << ' ';
                cout << '\n';
            }
            else {
                int k = idxs.size(), M = 300 * k / 2;

                vector<vector<int>> dp(k / 2 + 1, vector<int>(M + 1, -2));
                dp[0][0] = -1;

                for (auto &i: idxs) {
                    for (int j = k / 2 - 1; j >= 0; j --) {
                        for (int v = M; v >= 0; v --) {
                            if (dp[j][v] != -2 && v + 150 + nums[i] <= M && dp[j + 1][v + 150 + nums[i]] == -2) {
                                dp[j + 1][v + 150 + nums[i]] = i;
                            }
                        }
                    }
                }

                total = 0;
                for (auto &idx: idxs)
                    total += 150 + nums[idx];
                total /= 2;

                if (dp[k / 2][total] == -2) cout << "No\n";
                else {
                    cout << "Yes\n";
                    vector<int> vis(k, 0), i1, i2;

                    int cur = total;
                    for (int i = k / 2; i > 0; i --) {
                        i1.emplace_back(dp[i][cur]);
                        vis[dp[i][cur]] = 1;
                        cur -= 150 + nums[dp[i][cur]];
                    }

                    for (int i = 0; i < k; i ++) {
                        if (!vis[i]) {
                            i2.emplace_back(i);
                        }
                    }

                    cur = 0;
                    for (int i = 0; i < k / 2; i ++) {
                        int v1 = i1[i];
                        cur = nums[v1] - cur;
                        ans[v1] = cur;
                        int v2 = i2[i];
                        cur = nums[v2] - cur;
                        ans[v2] = cur;
                    }
                    
                    for (int i = 0; i < n; i ++)
                        cout << ans[i] << ' ';
                    cout << '\n';
                    for (int i = 0; i < n; i ++)
                        cout << nums[i] - ans[i] << ' ';
                    cout << '\n';
                }
            }
        }
    }

    return 0;
}