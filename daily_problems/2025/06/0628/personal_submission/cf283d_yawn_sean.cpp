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

    vector<long long> nums(n);
    vector<int> cnt2(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        while (!(nums[i] & 1)) {
            nums[i] >>= 1;
            cnt2[i] ++;
        }
    }

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            if (nums[j] % nums[i] == 0 && (cnt2[i] - cnt2[j] == i - j || cnt2[i] <= i - j - 1)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << n - *max_element(dp.begin(), dp.end());

    return 0;
}