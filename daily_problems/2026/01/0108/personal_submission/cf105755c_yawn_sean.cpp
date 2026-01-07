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

    vector<int> vis(1 << 22, 0);
    for (auto &x: nums) {
        int bit = 32 - __builtin_clz(x);
        vis[((1 << bit) - 1) ^ x] |= 1 << (bit - 1);
    }

    for (int i = 0; i < 22; i ++) {
        for (int j = 0; j < 1 << 22; j ++) {
            if (j >> i & 1) {
                vis[j ^ (1 << i)] |= vis[j];
            }
        }
    }

    vector<int> dp(1 << 22, 0);
    for (int i = 0; i < 1 << 22; i ++) {
        for (int j = 0; j < 22; j ++) {
            if (vis[i] >> j & 1) {
                int ni = i | (1 << j);
                dp[ni] = max(dp[ni], dp[i] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

	return 0;
}