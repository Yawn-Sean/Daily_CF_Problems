#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

pair<int, int> op(pair<int, int> x, pair<int, int> y) {return min(x, y);}
pair<int, int> e() {return {1'000'000, 0};}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        nums.emplace_back(nums[i]);
    }

    for (int i = 0; i < 2 * n; i ++)
        nums[i] = max(0, i - nums[i]);

    vector<pair<int, int>> ar(2 * n);
    for (int i = 0; i < 2 * n; i ++)
        ar[i] = {nums[i], i};
    
    atcoder::segtree<pair<int, int>, op, e> seg(ar);

    vector<vector<int>> nth_step(20, vector<int>(2 * n, 0));
    for (int i = 0; i < 2 * n; i ++)
        nth_step[0][i] = seg.prod(nums[i], i + 1).second;
    
    for (int i = 0; i < 19; i ++) {
        for (int j = 0; j < 2 * n; j ++) {
            nth_step[i + 1][j] = nth_step[i][nth_step[i][j]];
        }
    }

    long long ans = 0;
    for (int i = n; i < 2 * n; i ++) {
        if (i - nums[i] >= n - 1) {
            ans ++;
            continue;
        }
        int cur = i;
        for (int j = 19; j >= 0; j --) {
            if (i - nums[nth_step[j][cur]] < n - 1) {
                ans += 1 << j;
                cur = nth_step[j][cur];
            }
        }
        ans += 2;
    }

    cout << ans;

    return 0;
}