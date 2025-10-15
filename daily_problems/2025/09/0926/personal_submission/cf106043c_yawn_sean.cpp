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

    vector<int> left(n), right(n), stk;
    
    stk = {-1};
    for (int i = 0; i < n; i ++) {
        while (stk.back() != -1 && nums[stk.back()] <= nums[i])
            stk.pop_back();
        left[i] = stk.back();
        stk.emplace_back(i);
    }

    stk = {n};
    for (int i = n - 1; i >= 0; i --) {
        while (stk.back() != n && nums[stk.back()] <= nums[i])
            stk.pop_back();
        right[i] = stk.back();
        stk.emplace_back(i);
    }

    vector<int> max_length(n + 1, 0), ans(n + 1, 0);

    for (int i = 0; i < n; i ++)
        if (nums[i] < n)
            max_length[nums[i]] = max(max_length[nums[i]], right[i] - left[i] - 1);
 
    for (int i = 1; i <= n; i ++)
        max_length[i] = min(max_length[i], max_length[i - 1]);
 
    for(int i = 0; i <= n; i ++)
        ans[max_length[i]] = i + 1;
    
    for (int i = n - 1; i >= 0; i --)
        ans[i] = max(ans[i], ans[i + 1]);
    
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << ' ';

    return 0;
}