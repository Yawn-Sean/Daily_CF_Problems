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

    int n;
    cin >> n;

    int k1, k2;

    cin >> k1;
    vector<int> s1(k1);
    for (auto &x: s1) cin >> x;

    cin >> k2;
    vector<int> s2(k2);
    for (auto &x: s2) cin >> x;

    vector<vector<int>> dp(2, vector<int>(n, 0)), cnt(2, vector<int>(n, 0));
    dp[0][0] = 2;
    dp[1][0] = 2;

    auto dfs = [&] (auto &self, int person, int pos) -> void {
        if (person) {
            for (auto &step: s1) {
                int last_pos = (pos + n - step) % n;
                if (dp[0][last_pos] == 0) {
                    if (dp[person][pos] == 2)
                        dp[0][last_pos] = 1, self(self, 0, last_pos);
                    else {
                        cnt[0][last_pos] ++;
                        if (cnt[0][last_pos] == k1)
                            dp[0][last_pos] = 2, self(self, 0, last_pos);
                    }
                }
            }
        }
        else {
            for (auto &step: s2) {
                int last_pos = (pos + n - step) % n;
                if (dp[1][last_pos] == 0) {
                    if (dp[person][pos] == 2)
                        dp[1][last_pos] = 1, self(self, 1, last_pos);
                    else {
                        cnt[1][last_pos] ++;
                        if (cnt[1][last_pos] == k2)
                            dp[1][last_pos] = 2, self(self, 1, last_pos);
                    }
                }
            }
        }
    };

    dfs(dfs, 0, 0);
    dfs(dfs, 1, 0);

    vector<string> strs = {"Loop", "Win", "Lose"};

    for (int i = 0; i < 2; i ++) {
        for (int j = 1; j < n; j ++) cout << strs[dp[i][j]] << ' ';
        cout << '\n';
    }

    return 0;
}