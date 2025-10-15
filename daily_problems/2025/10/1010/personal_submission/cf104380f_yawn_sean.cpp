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

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    int x = min(n - r, l - 1);
    while (x --)
        nums.pop_back();
    
    sort(nums.rbegin(), nums.rend());

    long long ans = 0;
    for (int i = 0; i <= r - l; i ++)
        ans += nums[i];
    
    cout << ans;

    return 0;
}