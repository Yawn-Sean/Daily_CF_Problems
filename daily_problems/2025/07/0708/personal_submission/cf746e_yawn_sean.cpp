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

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    set<int> vis0, vis1;

    int v = n / 2;
    vector<bool> chosen(n, 0);

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] > nums[j];});

    for (auto &i: order) {
        if (nums[i] & 1) {
            if (vis1.size() < v && vis1.find(nums[i]) == vis1.end()) {
                vis1.insert(nums[i]);
                chosen[i] = 1;
            }
        }
        else {
            if (vis0.size() < v && vis0.find(nums[i]) == vis0.end()) {
                vis0.insert(nums[i]);
                chosen[i] = 1;
            }
        }
    }

    int ans = 0, v0 = 2, v1 = 1, ma_val = 0;

    for (int i = 0; i < n; i ++) {
        if (!chosen[i]) {
            if (vis1.size() < v) {
                while (vis1.find(v1) != vis1.end()) v1 += 2;
                nums[i] = v1;
                vis1.insert(v1);
            }
            else {
                while (vis0.find(v0) != vis0.end()) v0 += 2;
                nums[i] = v0;
                vis0.insert(v0);
            }
            ma_val = max(ma_val, nums[i]);
            ans ++;
        }
    }

    if (ma_val > k) cout << -1;
    else {
        cout << ans << '\n';
        for (auto &v: nums) cout << v << ' ';
    }

    return 0;
}