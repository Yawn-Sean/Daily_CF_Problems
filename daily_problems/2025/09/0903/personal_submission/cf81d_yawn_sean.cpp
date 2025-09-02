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

    vector<int> nums(m);
    for (auto &x: nums) cin >> x;

    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] > nums[j];});

    vector<int> to_assign;
    for (auto &x: order) {
        int v = min(nums[x], n / 2);
        while ((v --) && to_assign.size() < n) {
            to_assign.emplace_back(x + 1);
        }
    }

    if (to_assign.size() < n) return cout << -1, 0;

    vector<int> ans(n);
    int pt = 0;

    for (auto &x: to_assign) {
        ans[pt] = x;
        pt += 2;
        if (pt >= n) pt = 1;
    }

    for (auto &x: ans) cout << x << ' ';

    return 0;
}