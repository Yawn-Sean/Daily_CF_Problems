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

    int mod = 998244353, ans = 1, cur = 0;

    for (int i = 0; i < n; i ++) {
        if (nums[i]) cur ++;
        else {
            ans = 1ll * ans * cur % mod;
            cur --;
        }
    }

    cur = 0;
    for (int i = n - 1; i >= n % 2; i --) {
        if (nums[i]) {
            ans = 1ll * ans * cur % mod;
            cur --;
        }
        else cur ++;
    }

    cout << ans;

	return 0;
}