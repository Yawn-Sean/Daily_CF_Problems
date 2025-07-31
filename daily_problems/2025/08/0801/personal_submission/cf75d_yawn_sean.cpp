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

    int inf = 1e5;
    vector<int> pref(n, -inf), suff(n, -inf), total(n, 0), res(n, -inf);

    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;

        vector<int> nums(k);
        for (auto &v: nums)
            cin >> v;

        for (auto &v: nums) {
            total[i] += v;
            pref[i] = max(pref[i], total[i]);
        }

        int cur;

        cur = 0;
        for (auto &v: nums) {
            cur = max(cur, 0) + v;
            res[i] = max(res[i], cur);
        }

        reverse(nums.begin(), nums.end());
        cur = 0;
        for (auto &v: nums) {
            cur += v;
            suff[i] = max(suff[i], cur);
        }
    }

    long long cur = 0, ans = -inf;
    while (m --) {
        int idx;
        cin >> idx;
        idx --;

        ans = max(ans, (long long)res[idx]);
        ans = max(ans, cur + pref[idx]);
        cur = max(cur + total[idx], (long long)suff[idx]);
    }
    cout << ans;

    return 0;
}