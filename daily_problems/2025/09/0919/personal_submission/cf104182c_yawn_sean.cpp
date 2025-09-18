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

    long long ans = 1ll * n * (n + 1) / 2 + 1;

    vector<int> stk = {-1};
    for (int i = 0; i < n; i ++) {
        while (stk.back() != -1 && nums[i] >= nums[stk.back()])
            stk.pop_back();
        ans -= i - stk.back();
        stk.emplace_back(i);
    }

    stk = {n};
    for (int i = n - 1; i >= 0; i --) {
        while (stk.back() != n && nums[i] <= nums[stk.back()])
            stk.pop_back();
        ans -= stk.back() - i;
        stk.emplace_back(i);
    }

    vector<int> stk1 = {n}, stk2 = {n};

    for (int i = n - 1; i >= 0; i --) {
        while (stk1.back() != n && nums[i] > nums[stk1.back()])
            stk1.pop_back();
        
        while (stk2.back() != n && nums[i] <= nums[stk2.back()])
            stk2.pop_back();
        
        int l = 0, r = stk1.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (stk1[mid] >= stk2.back()) l = mid + 1;
            else r = mid - 1;
        }

        ans += stk1.size() - l + 1;
        stk1.emplace_back(i);
        stk2.emplace_back(i);
    }

    cout << ans;

    return 0;
}