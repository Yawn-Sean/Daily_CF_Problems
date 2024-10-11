#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> pref_val(n, 0), suff_val(n, 0);
    vector<long long> pref_tot(n, 0), suff_tot(n, 0);

    for (int i = 0; i < n - 1; i ++) {
        pref_val[i + 1] = max(pref_val[i] + 1, nums[i]);
        pref_tot[i + 1] = pref_tot[i] + pref_val[i + 1] - nums[i];
    }

    for (int i = n - 1; i > 0; i --) {
        suff_val[i - 1] = max(suff_val[i] + 1, nums[i]);
        suff_tot[i - 1] = suff_tot[i] + suff_val[i - 1] - nums[i];
    }

    long long ans = 1e15;
    for (int i = 0; i < n; i ++)
        ans = min(ans, pref_tot[i] + suff_tot[i] + max(0, max(pref_val[i], suff_val[i]) + 1 - nums[i]));
    
    cout << ans;

    return 0;
}