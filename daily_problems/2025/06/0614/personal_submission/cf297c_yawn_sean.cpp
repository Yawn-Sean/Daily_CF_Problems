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

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] < nums[j];});

    int k1 = (n + 2) / 3, k2 = n - k1;
    vector<int> ans1(n), ans2(n);

    for (int i = 0; i < k1; i ++) {
        int u = order[i];
        ans1[u] = i;
        ans2[u] = nums[u] - ans1[u];
    }

    for (int i = k1; i < k2; i ++) {
        int u = order[i];
        ans2[u] = i;
        ans1[u] = nums[u] - ans2[u];
    }

    for (int i = k2; i < n; i ++) {
        int u = order[i];
        ans2[u] = n - 1 - i;
        ans1[u] = nums[u] - ans2[u];
    }

    cout << "YES\n";
    for (auto &v: ans1) cout << v << ' '; cout << '\n';
    for (auto &v: ans2) cout << v << ' '; cout << '\n';

    return 0;
}