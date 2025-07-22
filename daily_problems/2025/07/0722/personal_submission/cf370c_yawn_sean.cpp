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

    int n, m;
    cin >> n >> m;

    vector<int> nums(n), cnt(m + 1, 0);
    for (auto &v: nums)
        cin >> v, cnt[v] ++;
    
    int k = *max_element(cnt.begin(), cnt.end());

    sort(nums.begin(), nums.end());

    cout << min(n, 2 * n - 2 * k) << '\n';

    for (int i = 0; i < n; i ++)
        cout << nums[i] << ' ' << nums[(i + k) % n] << '\n';

    return 0;
}