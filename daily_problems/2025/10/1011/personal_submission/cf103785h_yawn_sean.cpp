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

    vector<int> nums(n), ops;
    for (auto &x: nums) cin >> x;

    for (int i = n - 1; i >= 0; i --) {
        bool flg = false;
        for (int j = i; j >= 0; j --) {
            if (nums[j] == j + 1) {
                flg = true;
                ops.emplace_back(nums[j]);
                nums.erase(nums.begin() + j);
                break;
            }
        }
        if (!flg) return cout << "NO", 0;
    }

    reverse(ops.begin(), ops.end());

    cout << "YES\n";
    for (auto &op: ops) cout << op << ' ';

    return 0;
}