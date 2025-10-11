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

    int n, mod = 1e9 + 7;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums)
        cin >> x;

    vector<int> acc1(n + 1, 0), acc2(n + 1, 0);

    for (int i = 0; i < n; i ++) {
        acc1[i + 1] = (acc1[i] + nums[i]) % mod;
        acc2[i + 1] = (acc2[i] + 1ll * nums[i] * i % mod) % mod;
    }

    vector<int> left(n), right(n), stk;

    stk = {-1};

    for (int i = 0; i < n; i ++) {
        while (stk.back() != -1 && nums[stk.back()] <= nums[i])
            stk.pop_back();
        left[i] = stk.back();
        stk.emplace_back(i);
    }

    stk = {n};

    for (int i = n - 1; i >= 0; i --) {
        while (stk.back() != n && nums[stk.back()] <= nums[i])
            stk.pop_back();
        right[i] = stk.back();
        stk.emplace_back(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i ++) {
        ans += 1ll * nums[i] * (i - left[i]) % mod * (right[i] - i) % mod;
        ans %= mod;

        ans += 1ll * ((acc2[i] - acc2[left[i] + 1]) % mod - 1ll * (acc1[i] - acc1[left[i] + 1]) * left[i] % mod) % mod * (right[i] - i) % mod;
        ans %= mod;

        ans += 1ll * (1ll * (acc1[right[i]] - acc1[i + 1]) * right[i] % mod - (acc2[right[i]] - acc2[i + 1]) % mod) % mod * (i - left[i]) % mod;
        ans %= mod;
    }

    cout << (ans + mod) % mod;

    return 0;
}