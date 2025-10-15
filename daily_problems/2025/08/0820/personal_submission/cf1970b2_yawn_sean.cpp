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
    for (auto &x: nums) cin >> x;

    vector<int> st_range(n - 1);
    iota(st_range.begin(), st_range.end(), 1);
    sort(st_range.begin(), st_range.end(), [&] (int i, int j) {return nums[i] > nums[j];});

    vector<int> xs(n, 1), ys(n, 1), target(n, 0);

    int last_idx = 0;

    for (int i = 0; i < n - 1; i ++) {
        int idx = st_range[i];
        nums[idx] --;

        xs[idx] = xs[last_idx] + 1;
        if (ys[last_idx] + nums[idx] >= 1 && ys[last_idx] + nums[idx] <= n)
            ys[idx] = ys[last_idx] + nums[idx];
        else
            ys[idx] = ys[last_idx] - nums[idx];
        
        if (nums[idx] < 0) target[idx] = idx;
        else target[idx] = last_idx;
        
        last_idx = idx;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i ++)
        cout << xs[i] << ' ' << ys[i] << '\n';
    
    for (auto &v: target) cout << v + 1 << ' ';

    return 0;
}