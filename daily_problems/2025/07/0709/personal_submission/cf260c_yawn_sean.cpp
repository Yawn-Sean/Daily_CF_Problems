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

    int n, x;
    cin >> n >> x;

    vector<long long> nums(n);
    for (auto &v: nums) cin >> v;

    x --;
    long long mn = *min_element(nums.begin(), nums.end());

    for (auto &v: nums) v -= mn;
    mn *= n;

    while (nums[x]) {
        nums[x] --, mn ++;
        x = (x + n - 1) % n;
    }

    nums[x] = mn;
    for (auto &v: nums) cout << v << ' ';

    return 0;
}