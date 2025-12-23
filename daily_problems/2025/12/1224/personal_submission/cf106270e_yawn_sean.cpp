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

    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    int mod = 1e9 + 7;
    int cur_ma = 0, step = 1;

    vector<int> pref_steps(n);
    map<int, vector<int>> pos;

    for (int i = 0; i < n; i ++) {
        pref_steps[i] = step;
        if (nums[i] > cur_ma) {
            cur_ma = nums[i];
            step = 0;
        }
        step ++;

        pos[nums[i]].emplace_back(i);
    }

    vector<int> pref_max = nums;
    for (int i = 1; i < n; i ++) {
        pref_steps[i] = max(pref_steps[i - 1], pref_steps[i]);
        pref_max[i] = max(pref_max[i - 1], pref_max[i]);
    }

    int rev2 = (mod + 1) / 2;
    vector<int> rev2_pows(n + 1);
    rev2_pows[0] = 1;

    for (int i = 1; i <= n; i ++)
        rev2_pows[i] = 1ll * rev2_pows[i - 1] * rev2 % mod;

    auto solve = [&] (int idx, int k) -> int {
        auto &to_find = pos[nums[idx]];
        int last_pos = min(to_find[0] + k, n - 1);
        if (pref_max[last_pos] > nums[idx]) return 0;
        if (pref_steps[last_pos] > k) return 0;
        if (last_pos < idx) return 0;

        int ans = (to_find[0] == idx ? 1 : rev2);
        auto r = upper_bound(to_find.begin(), to_find.end(), last_pos);
        auto l = upper_bound(to_find.begin(), to_find.end(), idx);
        ans = 1ll * ans * rev2_pows[r - l] % mod;
        return ans;
    };

    while (q --) {
        int t;
        cin >> t;

        if (t == 1) {
            int idx, k;
            cin >> idx >> k;
            cout << solve(idx - 1, k) << '\n';
        }
        else {
            int idx;
            cin >> idx;
            idx --;
            int k = pref_steps[idx];
            cout << k << ' ' << solve(idx, k) << '\n';
        }
    }

	return 0;
}