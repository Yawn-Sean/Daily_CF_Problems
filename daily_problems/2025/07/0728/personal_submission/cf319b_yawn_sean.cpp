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

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> stk;
    vector<int> dp(n);

    for (int i = n - 1; i >= 0; i --) {
        int res = 0;

        while (!stk.empty() && nums[stk.back()] < nums[i]) {
            res = max(res + 1, dp[stk.back()]);
            stk.pop_back();
        }

        stk.emplace_back(i);
        dp[i] = res;
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}