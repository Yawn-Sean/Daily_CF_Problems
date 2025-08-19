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
    long long k;
    cin >> n >> k;
    k --;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    sort(nums.begin(), nums.end());

    int i = 0, j;

    while (i < n) {
        j = i;
        while (j < n && nums[i] == nums[j])
            j ++;
        if (k < 1ll * (j - i) * n) break;
        k -= 1ll * (j - i) * n;
        i = j;
    }

    cout << nums[i] << ' ' << nums[k / (j - i)];

    return 0;
}