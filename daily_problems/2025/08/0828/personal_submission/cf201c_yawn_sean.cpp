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

    vector<int> nums(n - 1);
    for (auto &x: nums) cin >> x;

    vector<long long> left0(n, 0), left1(n, 0), right0(n, 0), right1(n, 0);

    for (int i = 0; i < n - 1; i ++) {
        if (nums[i] > 1) left1[i + 1] = left1[i] + nums[i] / 2 * 2;
        left0[i + 1] = max(left0[i] + nums[i] - (nums[i] + 1) % 2, left1[i] + nums[i]);
    }

    for (int i = n - 2; i >= 0; i --) {
        if (nums[i] > 1) right1[i] = right1[i + 1] + nums[i] / 2 * 2;
        right0[i] = max(right0[i + 1] + nums[i] - (nums[i] + 1) % 2, right1[i + 1] + nums[i]);
    }

    long long ans = 0;

    for (int i = 0; i < n; i ++) {
        ans = max(ans, left0[i] + right1[i]);
        ans = max(ans, left1[i] + right0[i]);
    }

    cout << ans;

    return 0;
}